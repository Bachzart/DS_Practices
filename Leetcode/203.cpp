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

/* method 1 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *L = new ListNode;
        ListNode *p = L, *cur;
        p->next = head;
        while(p) {
            if(p->next && p->next->val == val) {
                cur = p->next;
                p->next = cur->next;
                delete(cur);
            } else p = p->next;
        }
        p = L;
        L = L->next;
        delete(p);
        return L;
    }
};

/* method 2 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};