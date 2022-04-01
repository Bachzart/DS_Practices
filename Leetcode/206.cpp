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

/* method 1: use stack */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        stack<ListNode*> st;
        ListNode* p = head;
        while(p) {
            st.push(p);
            p = p->next;
        }
        ListNode* t = st.top();
        p = t;
        st.pop();
        while(!st.empty()) {
            p->next = st.top();
            st.pop();
            p = p->next;
        }
        p->next = nullptr;
        return t;
    }
};

/* method 2: no stack */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *pre = nullptr, *cur = head, *next;
        while(cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

/* method 3: recursion */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        cout << newhead->val << endl;
        return newhead;
    }
};

/* method 4 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* L = new ListNode(0);
        ListNode *p = L, *t = L;
        while(head) {
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
};