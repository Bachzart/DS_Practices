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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode *cur = head, *p;
        while(cur) {
            if(cur->next != nullptr && cur->val == cur->next->val) {
                p = cur->next;
                cur->next = p->next;
                delete(p);
            } else cur = cur->next;
        }
        return head;
    }
};

/* method 2 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val) head->next = head->next->next;
        return head;
    }
};