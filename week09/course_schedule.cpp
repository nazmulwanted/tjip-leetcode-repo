// Time complexity: O(N), N = Number of courses.
// Space complexity: O(N), N = Number of courses.

bool hasCycle(vector<int> &col, vector<vector<int>> &graph, int u){
    col[u] = 1;
    bool status = false;
    for(auto v: graph[u]){
        if(col[v] == 1) status = true;
        else if(col[v] == 0){
            status |= hasCycle(col, graph, v);
        }
    }
    col[u] = 2;
    return status;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<vector<int>> graph(numCourses);
    vector<int> col(numCourses, 0);
    for(auto pre: prerequisites){
        graph[pre[1]].push_back(pre[0]);
    }
    for(int i = 0; i < numCourses; i++){
        if(hasCycle(col, graph, i)) return false;
    }
    return true;
}
