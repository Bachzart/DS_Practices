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

/* method 1: use one pointer */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *tmp = head;
        int cnt = 0;
        while(tmp) {
            cnt++;
            tmp = tmp->next;
        }
        tmp = head;
        for(int i = 0; i < cnt / 2; i++) tmp = tmp->next;
        return tmp;
    }
};

/* method 2: use two pointers */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *slow = head, *fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

/* method 3: use array */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        vector<ListNode*> arr = {head};
        while(arr.back()->next != nullptr) {
            arr.push_back(arr.back()->next);
        }
        return arr[arr.size() / 2];
    }
};