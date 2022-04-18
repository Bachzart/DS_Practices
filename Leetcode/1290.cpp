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
    int getDecimalValue(ListNode* head) {
        ListNode *p = head;
        int ret = 0, cnt = 0;
        while(p) {
            cnt++;
            p = p->next;
        }
        p = head;
        cnt--;
        while(p) {
            if(p->val) ret += (1 << cnt);
            cnt--;
            p = p->next;
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *p = head;
        int ret = 0;
        while(p) {
            ret <<= 1;
            ret |= p->val;
            p = p->next;
        }
        return ret;
    }
};