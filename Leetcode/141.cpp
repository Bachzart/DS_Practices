/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* method 1 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *p = head;
        unordered_set<ListNode*> ht;
        while(p) {
            if(ht.find(p) != ht.end()) return true;
            ht.insert(p);
            p = p->next;
        }
        return false;
    }
};

/* method 2 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow = head, *fast = head->next;
        while(fast && slow != fast) {
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        return fast != nullptr;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};