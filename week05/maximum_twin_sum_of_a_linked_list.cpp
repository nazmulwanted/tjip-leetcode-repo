// Time complexity: O(N), N is number of nodes.
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

int pairSum(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = reverseList(slow);
    int max_result = INT_MIN;
    while(slow){
        max_result = max(max_result, slow->val + head->val);
        slow = slow->next;
        head = head->next;
    }
    return max_result;
}
