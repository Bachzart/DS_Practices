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
/*
Method 2
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        auto slow = head, fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto mid = slow;
        ListNode* pre = nullptr;
        while(mid) {
            auto nxt = mid->next;
            mid->next = pre;
            pre = mid;
            mid = nxt;
        }
        int ans = 0;
        auto head2 = pre;
        while(head2) {
            ans = max(ans, head->val + head2->val);
            head = head->next, head2 = head2->next;
        }
        return ans;
    }
};

/*
Method 1: use extra storage

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vals;
        while(head != nullptr) {
            vals.push_back(head->val);
            head = head->next;
        }

        int ans = INT_MIN;
        for(int left = 0, right = vals.size() - 1; left < right; ++left, --right) {
            ans = max(ans, vals[left] + vals[right]);
        }
        return ans;
    }
};
*/