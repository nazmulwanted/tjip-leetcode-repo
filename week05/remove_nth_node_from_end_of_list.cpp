// Time complexity: O(N), N = number of nodes;
// Space complexity: O(1);

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* currNode = head;
    ListNode* dummyNode = head;
    while(n--){
        dummNode = dummyNode->next;
    }
    if(!dummyNode) return head->next;
    while(dummyNode->next){
        dummyNode = dummyNode->next;
        currNode = currNode->next;
    }
    currNode->next = currNode->next->next;
    return head;
}
