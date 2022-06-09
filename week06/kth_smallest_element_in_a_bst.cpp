// Time complexity: O(N), N = Number of nodes;
// Space complexity: O(1)


void traverseTree(TreeNode* root, int &k, int &kthValue){
    if(!root) return;
    traverseTree(root->left, k, kthValue);
    k--;
    if(k == 0){
        kthValue = root->val;
    }
    traverseTree(root->right, k, kthValue);
}

int kthSmallest(TreeNode* root, int k){
    int kthValue;
    traverseTree(root, k, kthValue);
    return kthValue;
}
