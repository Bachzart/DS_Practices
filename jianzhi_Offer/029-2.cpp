/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == nullptr) {
            head = new Node(insertVal);
            head->next = head;
        } else if(head == head->next) {
            Node* tmp = new Node(insertVal, head);
            head->next = tmp;
        } else {
            Node *p = head;
            while(p->next != head) {
                if(p->val > insertVal && p->next->val > insertVal && p->val > p->next->val) {
                    Node* tmp = new Node(insertVal, p->next);
                    p->next = tmp;
                    break;
                } else if(p->val < insertVal && p->next->val > insertVal) {
                    Node* tmp = new Node(insertVal, p->next);
                    p->next = tmp;
                    break;
                } else if(p->val == insertVal) {
                    Node* tmp = new Node(insertVal, p->next);
                    p->next = tmp;
                    break;
                }
                p = p->next;
            }
            if(p->next == head) {
                Node* tmp = new Node(insertVal, p->next);
                p->next = tmp;
            }
        }
        return head;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node *node = new Node(insertVal);
        if(head == nullptr) {
            head = node;
            head->next = head;
        } else if(head == head->next) {
            head->next = node;
            node->next = head;
        } else {
            Node *cur = head, *next = head->next;
            while(next != head) {
                if(cur->val <= insertVal && insertVal <= next->val) break;
                if(cur->val > next->val) {
                    if(insertVal > cur->val || insertVal < next->val) break;
                }
                cur = cur->next;
                next = next->next;
            }
            cur->next = node;
            node->next = next;
        }
        return head;
    }
};
