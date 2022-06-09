// Time complexity: O(N), N = Number of nodes
// Space complexity: O(1)

void traverseNode(Node* node){
    if(!root) return;
    if(node->left) node->left->next = node->right;
    if(node->right && node->next) node->right->next = node->next->left;

    if(node->left) traverseNode(node->left);
    if(node->right) traverseNode(node->right);
}

Node* connect(Node* root){
    traverseNode(root);
    return root;
}
