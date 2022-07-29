// Time complexity: O(N), N = Number of elements in an array.
// Space complexity: O(N)
//

void verify_bst(vector<int> &preorder, int &curr_index,  int left, int right){
    if(curr_index >= preorder.size()) return;
    int value = preorder[curr_index];
    if(value < left || value > right) return;
    curr_index++;
    verify_bst(preorder, curr_index, left, value - 1);
    verify_bst(preorder, curr_index, value + 1, right);
}

bool verify_preorder(vector<int> &preorder){
    int curr_index = 0;
    verify_bst(preorder, curr_index, INT_MIN, INT_MAX);
    return curr_index == preorder.size();
}
