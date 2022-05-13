/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

/* hash */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, int> ht;
        vector<Node*> nodes;
        Node *p = head;
        int index = 0;
        while(p) {
            ht[p] = index++;
            Node *node = new Node(p->val);
            nodes.push_back(node);
            p = p->next;
        }
        int indices[1005];
        memset(indices, -1, sizeof(indices));
        p = head;
        index = 0;
        while(p) {
            if(p->random != nullptr) indices[index] = ht[p->random];
            index++;
            p = p->next;
        }
        for(int i = 1; i < index; i++) {
            nodes[i - 1]->next = nodes[i];
        }
        for(int i = 0; i < index; i++) {
            if(indices[i] != -1) nodes[i]->random = nodes[indices[i]];
        }
        return nodes[0];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> ht;
        vector<Node*> nodes;
        Node *p = head;
        int cnt = 0;
        while(p) {
            Node *node = new Node(p->val);
            node->random = p->random;
            ht[p] = node;
            nodes.push_back(node);
            p = p->next;
            cnt++;
        }
        for(int i = 0; i < cnt; i++) {
            nodes[i]->random = ht[nodes[i]->random];
        }
        for(int i = 1; i < cnt; i++) {
            nodes[i - 1]->next = nodes[i];
        }
        return nodes[0];
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> ht;
        Node *L = new Node(INT_MAX);
        Node *p = head, *t = L;
        while(p) {
            Node *node = new Node(p->val);
            node->random = p->random;
            t->next = node;
            t = t->next;
            ht[p] = node;
            p = p->next;
        }
        t = L;
        L = L->next;
        delete(t);
        t = L;
        while(t) {
            if(ht.count(t->random)) t->random = ht[t->random];
            t = t->next;
        }
        cout << endl;
        return L;
    }
};

/* hash + back tracking */
class Solution {
public:
    unordered_map<Node*, Node*> ht;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(!ht.count(head)) {
            Node *node = new Node(head->val);
            ht[head] = node;
            node->next = copyRandomList(head->next);
            node->random = copyRandomList(head->random);
        }
        return ht[head];
    }
};

/* node split */
class Solution {
public:
    unordered_map<Node*, Node*> ht;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        for(Node *node = head; node != nullptr; node = node->next->next) {
            Node *nodenew = new Node(node->val);
            nodenew->next = node->next;
            node->next = nodenew;
        }
        for(Node *node = head; node != nullptr; node = node->next->next) {
            Node *nodenew = node->next;
            nodenew->random = (node->random != nullptr) ? node->random->next : nullptr;
        }
        Node *headnew = head->next;
        for(Node *node = head; node != nullptr; node = node->next) {
            Node *nodenew = node->next;
            node->next = node->next->next;
            nodenew->next = (nodenew->next != nullptr) ? nodenew->next->next : nullptr;
        }
        return headnew;
    }
};