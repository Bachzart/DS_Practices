/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* stack */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next) return;
        stack<ListNode*> st;
        ListNode *p = head;
        int cnt = 0;
        while(p) {
            st.push(p);
            cnt++;
            p = p->next;
        }
        p = head;
        for(int i = 1; i < cnt; i++) {
            if(i % 2) {
                ListNode *tmp = p->next;
                p->next = st.top();
                st.pop();
                p = p->next;
                p->next = tmp;
            } else p = p->next;
        }
        p->next = nullptr;
    }
};

/* find middle node + reverse list + merge list */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head->next) return;
        ListNode *mid = middleNode(head);
        ListNode *L1 = head;
        ListNode *L2 = mid->next;
        mid->next = nullptr;
        L2 = reverseList(L2);
        mergeTwoLists(L1, L2);
    }
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* L = new ListNode(0);
        ListNode *p = L, *t = L;
        while(head != nullptr) {
            t = head;
            head = head->next;
            t->next = p->next;
            p->next = t;
        }
        p = L;
        p = p->next;
        delete(L);
        return p;
    }
    void mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1;
        ListNode *p2;
        while(list1 != nullptr && list2 != nullptr) {
            p1 = list1->next;
            p2 = list2->next;
            
            list1->next = list2;
            list1 = p1;
            
            list2->next = list1;
            list2 = p2;
        }
    }
};