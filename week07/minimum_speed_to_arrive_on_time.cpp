// Time complexity: O(N * log M) , N = number of distances, M = Number of possible speeds.
// Space complexity: O(1)

bool isInTime(vector<int> &dist, double hour, long long speed){
    double time = 0;
    for(auto &d : dist){
        time = ceil(time);
        time += (double)d / speed;
        if(time > hour) return false;
    }
    return true;
}

int minSpeedOnTime(vector<int> &dist, double hour){
    if(hour < dist.size() - 1) return -1;
    long long left = 1, right = 1e7;  
    while(left <= right){
        long long mid = (left + right) / 2;
        if(isInTime(dist, hour, mid)) right = mid - 1;
        else left = mid + 1;
    }
    return left > 1e7 ? -1 : left;
}
