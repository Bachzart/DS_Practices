/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
method 1: two pointers
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast != nullptr) {
            slow = slow->next;
            if(fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if(fast == slow) {
                ListNode *ptr = head;
                while(ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};


/*

method 2: hash

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> ht;
        while(head != nullptr) {
            ht.insert(head);
            head = head->next;
            if(ht.count(head))
                break;
        }
        return head;
    }
};
*/