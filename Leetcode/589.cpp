/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/* method 1 */
class Solution {
public:
    void pre(Node *root, vector<int>& ret) {
        if(!root) return;
        ret.push_back(root->val);
        for(int i = 0; i < root->children.size(); i++) {
            pre(root->children[i], ret);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> ret;
        pre(root, vector<int>& ret);
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<Node*> st;
        unordered_map<Node*, int> ht;
        Node *node = root;
        while(!st.empty() || node != nullptr) {
            while(node != nullptr) {
                ret.push_back(node->val);
                st.push(node);
                if(node->children.size() > 0) {
                    ht[node] = 0;
                    node = node->children[0];
                } else node = nullptr;
            }
            node = st.top();
            int index = (ht.count(node) ? ht[node] : -1) + 1;
            if(index < node->children.size()) {
                ht[node] = index;
                node = node->children[index];
            } else {
                st.pop();
                ht.erase(node);
                node = nullptr;
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(!root) return ret;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()) {
            Node *node = st.top();
            st.pop();
            ret.push_back(node->val);
            for(auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                st.push(*it);
            }
        }
        return ret;
    }
};