// Time complexity: O(N), N = Number of nodes;
// Space complexity: O(1)

bool isBST(TreeNode* node, long long left, long long right){
    if(!root) return true;
    long long node_value = node->val;
    if(node_value >= left && node_value <= right){
        return isBST(node->left, left, node_value - 1) && isBST(node->right, node_value + 1, right);
    }
    return false;
}

bool isValidBST(TreeNode* root){
    return isBST(root, LLONG_MIN, LLONG_MAX);
}
