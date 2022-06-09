// Time complexity: O(N), N = Number of Nodes.
// Space complexity: O(N), N = Number of Nodes.

TreeNode* treeBuilding(vector<int> &preorder, vector<int> &inorder, int left, int right, int &pos, unordered_map<int, int> &pathMap){
    if(left > right) return NULL;
    TreeNode* currNode = new TreeNode(preorder[pos++]);
    int mid = pathMap[currNode->val];
    currNode->left = treeBuilding(preorder, inorder, left, mid - 1, pos, pathMap);
    currNode->right = treeBuilding(preorder, inorder, mid + 1, right, pos, pathMap);
    return currNode;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    int pos = 0;
    unordered_map<int, int> pathMap;
    int arrLength = inorder.size();
    for(int i = 0; i < arrLength; i++){
        pathMap[inorder[i]] = i;
    }
    TreeNode* root = treeBuilding(preorder, inorder, 0, preorder.size() - 1, pos, pathMap);
    return root;
}
