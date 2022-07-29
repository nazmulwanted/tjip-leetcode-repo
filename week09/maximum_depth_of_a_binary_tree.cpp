// Time complexity: O(N), N = Number of nodes.
// Space complexity: O(1)

int maxDepth(TreeNode* root, int depth = 0){
    if(!root) return depth;
    return max(maxDepth(root->left, depth + 1), maxDepth(root->right, depth + 1));
}
