// Time complexity: O(N * log N) + O(N), N = Number of people or people queue length.
// Space complexity: O(N)

bool compare(vector<int> &a, vector<int> &b){
    return a[0] != b[0] ? a[0] > b[0] : a[1] < b[1];
}

vector<vector<int>> reconstructionQueue(vector<vector<int>> &people){
    sort(people.begin(), people.end(), compare);
    vector<vector<int>> q;
    int people_length = people.size();
    for(int i = 0; i < people_length; i++){
        q.insert(q.begin() + people[i][1], people[i]);
    }
    return q;
}
