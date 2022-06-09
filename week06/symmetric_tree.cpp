// Time complexity: O(N), N = Number of nodes;
// Space complexity: O(N), N = Number of nodes;

void nodeTraverseLeft(TreeNode* node, vector<int> &u){
    if(!node){
        u.push_back(1000); // i chose a random value outside of range.
        return;
    }
    u.push_back(node->val);
    nodeTraversalLeft(node->left, u);
    nodeTraversalLeft(node->right, u);
}
void nodeTraverseRight(TreeNode* node, vector<int> &v){
    if(!node){
        v.push_back(1000); // i chose a random value outside of range.
        return;
    }
    v.push_back(node->val);
    nodeTraversalLeft(node->left, v);
    nodeTraversalLeft(node->right, v);
}

bool isSymmetric(TreeNode* root){
    vector<int> a, b;
    nodeTraverseLeft(root->left, a);
    nodeTraverseRight(root->right, a);
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}
