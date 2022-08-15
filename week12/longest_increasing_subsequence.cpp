// Time complexity: O(n^2) , n = number of elements in the array.
// Space complexity: O(n).

int lengthOfLIS(vector<int> &nums){
    int nums_size = nums.size();
    int lis = 1;
    vector<int> lis_cache(nums_size, 1);
    for(int i = nums_size - 2; i >= 0; i--){
        for(int j = i + 1; j < nums_size; j++){
            if(nums[j] > nums[i]){
                lis_cache[i] = max( lis_cache[i], lis_cache[j] + 1);
                lis = max(lis_cache[i], lis);
            }
        }
    }
    return lis;
}
