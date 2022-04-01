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

/* method 1: no recursion */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                p->next = list1;
                p = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                p = list2;
                list2 = list2->next;
            }
        }
        if(list1) p->next = list1;
        if(list2) p->next = list2;
        p = head;
        p = p->next;
        delete(head);
        return p;
    }
};

/* method 2： recursion */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        else if(list2 == nullptr) return list1;
        else if(list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};