// Time complexity: O(N) , N = Number of nodes.
// Space complexity: O(1).

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root) return NULL;
    if(root->val == p->val || root->val == q->val) return root;
    TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);
    if(leftNode && rightNode) return root;
    return leftNode ? leftNode : rightNode;
}
