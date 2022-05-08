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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ret;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for(int i = 0; i < cnt; i++) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for(auto child: cur->children) {
                    q.push(child);
                }
            }
            ret.push_back(level);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<Node*> q;
        q.push(root);
        ret.push_back({root->val});
        while(!q.empty()) {
            queue<Node*> tmp;
            vector<int> v;
            while(!q.empty()) {
                Node *node = q.front(); q.pop();
                int size = node->children.size();
                for(int i = 0; i < size; i++) {
                    tmp.push(node->children[i]);
                    v.push_back(node->children[i]->val);
                }
            }
            q = tmp;
            if(v.size() != 0) ret.push_back(v);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int cnt = q.size();
            vector<int> level;
            for(int i = 0; i < cnt; i++) {
                Node* node = q.front(); q.pop();
                level.push_back(node->val);
                for(auto &child: node->children) {
                    q.push(child);
                }
            }
            ret.push_back(move(level));
        }
        return ret;
    }
};