// Time complexity: O(N), N is number of elements in the list.
// Space complexity: O(1)

bool hasCycle(ListNode* head){
    if(head == NULL) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
