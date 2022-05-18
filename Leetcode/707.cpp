/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int val): val(val), next(nullptr){};
    };
    MyLinkedList(){
        size = 0;
        dummyhead = new ListNode(0);
        tail = dummyhead;
    }
    
    int get(int index) {
        if(index < 0 || index > size - 1) return -1;
        ListNode *cur = dummyhead->next;
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode *newnode = new ListNode(val);
        newnode->next = dummyhead->next;
        dummyhead->next = newnode;
        size++;
        if(size == 1) tail = newnode;
    }
    
    void addAtTail(int val) {
        ListNode *newnode = new ListNode(val);
        tail->next = newnode;
        tail = newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size) return;
        ListNode *newnode = new ListNode(val);
        if(index == size) {
            tail->next = newnode;
            tail = newnode;
        } else {
            ListNode *cur = dummyhead;
            while(index--) cur = cur->next;
            newnode->next = cur->next;
            cur->next = newnode;    
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index > size - 1) return;
        ListNode *cur = dummyhead;
        while(index--) cur = cur->next;
        ListNode *tmp = cur->next;
        if(tmp == tail) tail = cur;
        cur->next = cur->next->next;
        delete tmp;
        size--;
    }
private:
    int size;
    ListNode *dummyhead;
    ListNode *tail;
};