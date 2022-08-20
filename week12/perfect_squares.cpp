// Time complexity: O(n * sqrt(n)), n is an given integer.
// Space complexity: O(n).

int findMinNumOfPerfectSquares(vector<int> &cache, int n){
    if(n == 0) return 0;
    if(cache[n] != -1) return cache[n];
    int minCount = INT_MAX / 2;
    for(int i = 1; i * i <= n; i++){
        minCount = min(minCount, 1 + findMinNumOfPerfectSquares(cache, n - (i * i)));
    }
    return cache[n] = minCount;
}

int numSquares(int n){
    vector<int> cache(n + 1, -1);
    return findMinNumOfPerfectSquares(cache, n);
}
