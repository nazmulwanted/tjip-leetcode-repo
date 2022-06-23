// Time complexity: O(N * log N) + O(N), N = Number of intervals.
// Space complexity: O(1)

bool compare(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>> &intervals){
    int number_of_overlaps = -1;
    sort(intervals.begin(), intervals.end(), compare);
    int prev_ending = intervals[0][1];
    for(auto interval : intervals){
        if(interval[0] >= prev_ending){
            prev_ending = interval[1];
        }
        else number_of_overlaps++;
    }
    return number_of_overlaps;
}
