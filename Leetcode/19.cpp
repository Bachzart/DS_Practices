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

/* method 1: use one pointers */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode* tmp = head;
        int cnt = 0;
        while(tmp != nullptr) {
            cnt++;
            tmp = tmp->next;
        }
        cnt -= n;
        tmp = head;
        ListNode* t;
        if(cnt == 0) {
            t = head;
            head = t->next;
        } else {
            for(int i = 0; i < cnt - 1; i++) tmp = tmp->next;
            t = tmp->next;
            tmp->next = t->next;
        }
        delete(t);
        return head;
    }
};

/* method 2: use two pointers */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        for(int i = 0; i < n; i++) first = first->next;
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        first = second->next;
        second->next = first->next;
        delete(first);
        first = dummy->next;
        delete(dummy);
        return first;
    }
};

/* method 3: use stack */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = new ListNode(0, head);
        stack<ListNode*> st;
        ListNode *tmp = dummy;
        while(tmp != nullptr) {
            st.push(tmp);
            tmp = tmp->next;
        }
        for(int i = 0; i < n; i++) {
            st.pop();
        }
        ListNode *pre = st.top();
        tmp = pre->next;
        pre->next = tmp->next;
        delete(tmp);
        pre = dummy->next;
        delete(dummy);
        return pre;
    }
};

/* method 4: use recursion */
class Solution {
public:
    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        head->next = removeNthFromEnd(head->next, n);
        cur++;
        if(n == cur) return head->next;
        return head;
    }
};