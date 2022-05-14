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
class Solution {
public:
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        return addTwoNumbers(l1, l2);
    }
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
        ListNode *L = new ListNode();
        ListNode *p = L;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int n1 = l1 != nullptr ? l1->val : 0;
            int n2 = l2 != nullptr ? l2->val : 0;
            int sum = n1 + n2 + carry;
            ListNode *tmp = new ListNode(sum % 10);
            carry = sum / 10;
            p->next = tmp;
            p = tmp;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        if(carry) p->next = new ListNode(carry);
        p = L;
        L = L->next;
        delete(p);
        return L;
    }
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