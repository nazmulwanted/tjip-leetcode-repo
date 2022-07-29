// Time complexity: O(2^N) , N = Number of elements in the array.
// Space complexity: O(2^N), N = Number of elements in the array.

void gen_subsets(int curr, vector<int> subset, vector<vector<int>> &subset_list, vector<int> &nums){
    if(curr == nums.size()){
        subset_list.push_back(subset);
        return;
    }
    subset.push_back(nums[curr]);
    gen_subsets(curr + 1, subset, subset_list, nums);
    subset.pop_back();
    gen_subsets(curr + 1, subset, subset_list, nums);
}

vector<vector<int>> subsets(vector<int> &nums){
    vector<vector<int>> subset_list;
    gen_subsets(0, {}, subset_list, nums);
    return subset_list;
}
