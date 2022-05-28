// Time complexity: O(N) , N is Number of Nodes.
// Space complexity: O(1)

void nodeTraverse(Node* node){
    if(!node) return;
    if(node->left) node->left->next = node->right;
    if(node->right && node->next) node->right->next = node->next->left;

    nodeTraverse(node->left);
    nodeTraverse(node->right);
}

Node* connect(Node* root){
    nodeTraverse(root);
    return root;
}
