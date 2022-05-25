// Time complexity: O(N), N = Number of nodes;
// Space complexity: O(1).

ListNode* reverseList(ListNode* head){
    if(head == NULL) return head;
    ListNode* currNode = head;
    ListNode* prevNode = NULL;
    while(currNode){
        ListNode* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}
