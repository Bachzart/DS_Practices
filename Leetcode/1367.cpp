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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/* dfs */
class Solution {
    bool dfs(TreeNode *rt, ListNode *head) {
        if(head == nullptr) return true;
        if(rt == nullptr) return false;
        if(rt->val != head->val) return false;
        return dfs(rt->left, head->next) || dfs(rt->right, head->next);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};

class Solution {
public:
    vector<string> paths;
    void dfs(TreeNode *root, string path) {
        if(!root) return;
        if(!root->left && !root->right) {
            path += to_string(root->val);
            paths.push_back(path);
            return;
        }
        path += to_string(root->val);
        dfs(root->left, path);
        dfs(root->right, path);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        string listseq;
        while(head) {
            listseq += to_string(head->val);
            head = head->next;
        }
        dfs(root, "");
        int size = paths.size();
        for(int i = 0; i < size; i++) {
            if(paths[i].find(listseq) != string::npos) return true;
        }
        return false;
    }
};

/* bfs */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        string listseq;
        while(head) {
            listseq += to_string(head->val);
            head = head->next;
        }
        queue<TreeNode*> q;
        queue<string> path;
        q.push(root);
        path.push(to_string(root->val));
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            string tmp = path.front(); path.pop();
            if(!node->left && !node->right) tmp += to_string(node->val);
            if(tmp.length() >= listseq.length()) {
                if(tmp.find(listseq) != string::npos) return true;
            }
            if(node->left) {
                q.push(node->left);
                path.push(tmp + to_string(node->left->val));
            }
            if(node->right) {
                q.push(node->right);
                path.push(tmp + to_string(node->right->val));
            } 
        }
        return false;
    }
};