/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* method 1: two pointers */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA;
        auto q = headB;
        while(p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};


/*
method 2: hash

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> ht;
        auto Lhead = headA;
        while(Lhead != nullptr) {
            ht.insert(Lhead);
            Lhead = Lhead->next;
        }
        Lhead = headB;
        while(Lhead != nullptr) {
            if(ht.count(Lhead))
                return Lhead;
            Lhead = Lhead->next;
        }
        return nullptr;
    }
};
*/