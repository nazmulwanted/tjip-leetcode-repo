// Time complexity: O(N) for adding an node or deleting an node at index where N is Number of elements in the list.
// Space complexity: O(1)

class MyLinkedLIst{
public:
    const static int DUMMYVALUE = INT_MIN;
    class LinkedListNode{
    public:
        int value;
        LinkedListNode* next;
        LinkedListNode(int val, LinkedListNode* nxt){
            value = val;
            next = nxt;
        }
    };

private:
    LinkedListNode* head;
    int listLength;

public:
    MyLinkedList(){
        len = 0;
        head = new LinkedListNode(DUMMYVALUE, NULL);
    }

    int get(int index){
        if(index < 0 || index >= listLength) return -1;
        LinkedListNode* currNode = head->next;
        while(index--){
            currNode = currNode->next;
        }
        return currNode->value;
    }

    void addAtHead(int val){
        addAtIndex(0, val);
    }

    void addAtTail(int val){
        addAtIndex(len, val);
    }

    void addAtIndex(int index, int val){
        if(index < 0 || index > listLength) return;
        LinkedListNode* currNode = head;
        while(index--){
            currNode = currNode->next;
        }
        LinkedListNode* nextToNewNode = currNode->next;
        currNode->next = new LinkedListNode(val, NULL);
        currNode->next->next = nextToNewNode;
        listLength++;
    }

    void deleteAtIndex(int index){
        if(index < 0 || index >= listLength) return;
        LinkedListNode* currNode = head;
        while(index--){
            currNode = currNode->next;
        }
        LinkedListNode* dumpNode = currNode->next;
        currNode->next = currNode->next->next;
        delete(dumpNode);
        listLength--;
    }
};
