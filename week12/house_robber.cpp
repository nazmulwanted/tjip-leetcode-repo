// Time complexity: O(N), N = Number of house
// Space complexity: O(N)

int max_money(int pos, vector<int> &cache, vector<int> &nums){
    if(pos >= nums.size()) return 0;
    if(cache[pos] != -1) return cache[pos];
    int max_money_rob = max(max_money(pos+1, cache, nums), nums[pos] + max_money(pos+2, cache, nums));
    return cache[pos] = max_money_rob;
}

int rob(vector<int> &nums){
    vector<int> cache(nums.size(), -1);
    return max_money(0, cache, nums);
}
