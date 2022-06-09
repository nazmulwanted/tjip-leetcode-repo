// Time complexity: O(N), N = Number of nodes;
// Space complexity: O(N), N = Number of nodes;

TreeNode* buildBST(vector<int>& nums, int left, int right){
    if(left > right) return NULL;

    int mid = left + (right - left) / 2;
    TreeNode* currNode = new TreeNode(nums[mid]);
    currNode->left = buildBST(nums, left, mid - 1);
    currNode->right = buildBST(nums, mid + 1, right);

    return currNode;
}

TreeNode* sortedArray(vector<int>& nums){
    return buildBST(nums, 0, nums.size() - 1);
}
