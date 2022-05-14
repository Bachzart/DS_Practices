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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *L = new ListNode();
        ListNode *p = L;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            } else carry = 0;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = tmp;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr) {
            int sum = l1->val + carry;
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            } else carry = 0;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = tmp;
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            int sum = l2->val + carry;
            if(sum > 9) {
                sum -= 10;
                carry = 1;
            } else carry = 0;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = tmp;
            l2 = l2->next;
        }
        if(carry) {
            ListNode *tmp = new ListNode(carry);
            p->next = tmp;
        }
        p = L;
        L = L->next;
        delete(p);
        return L;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
};