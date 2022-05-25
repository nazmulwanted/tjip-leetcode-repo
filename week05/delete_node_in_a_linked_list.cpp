// Time coplexity: O(1)
// Space complexity: O(1);

void deleteNode(ListNode* node){
    ListNode* nextNode = node->next;
    *(node) = *(node->next); // replacing value stored at node with value stored at next->next.
    delete nextNode; 
}
