// Time complexity: O(log N) , N = Array length.
// Space complexity: O(1)

int find_index(vector<int> &nums, int left, int right){
    if(left == right) return left;
    int mid = left + (right - left) / 2;
    int mid_next = mid + 1;
    if(nums[mid] > nums[mid_next]){
        return find_index(nums, left, mid);
    }
    else return find_index(nums, mid_next, right);
}

int find_peak_element(vector<int> &nums){
    return find_index(nums, 0, nums.size() - 1);
}
