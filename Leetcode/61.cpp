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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        vector<ListNode*> tmp, list;
        ListNode *p = head;
        while(p != nullptr) {
            tmp.push_back(p);
            p = p->next;
        }
        int size = tmp.size();
        k %= size;
        if(k == 0) return head;
        for(int i = size - k; i < size; i++) {
            list.push_back(tmp[i]);
        }
        for(int i = 0; i < size - k; i++) {
            list.push_back(tmp[i]);
        }
        for(int i = 0; i < size - 1; i++) {
            list[i]->next = list[i + 1];
        }
        list[size - 1]->next = nullptr;
        return list[0];
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        vector<ListNode*> list;
        ListNode *p = head;
        while(p != nullptr) {
            list.push_back(p);
            p = p->next;
        }
        int size = list.size();
        k %= size;
        if(k == 0) return head;
        for(int i = size - k; i < size - 1; i++) {
            list[i]->next = list[i + 1];
        }
        list[size - 1]->next = list[0];
        for(int i = 0; i < size - k - 1; i++) {
            list[i]->next = list[i + 1];
        }
        list[size - k - 1]->next = nullptr;
        return list[size - k];
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode *p = head;
        int cnt = 0;
        while(p != nullptr) {
            cnt++;
            p = p->next;
        }
        k %= cnt;
        if(k == 0) return head;
        p = head;
        ListNode *pre;
        int tmp = cnt - k;
        while(tmp--) {
            pre = p;
            p = p->next;
        }
        pre->next = nullptr;
        pre = p;
        while(p->next != nullptr) p = p->next;
        p->next = head;
        return pre;
    }
};