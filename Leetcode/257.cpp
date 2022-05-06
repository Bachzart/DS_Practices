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
    vector<string> ret;
public:
    void dfs(TreeNode *root, string path) {
        if(!root) return;
        if(!root->left && !root->right) {
            path += to_string(root->val);
            ret.push_back(path);
            return;
        }
        path += to_string(root->val);
        path += "->";
        dfs(root->left, path);
        dfs(root->right, path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ret;
        string path;
        dfs(root, path);
        return ret;
    }
};

/* bfs */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        queue<string> path;
        q.push(root);
        path.push(to_string(root->val));
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            string tmp = path.front(); path.pop();
            if(!node->left && !node->right) {
                ret.push_back(tmp);
            } else {
                if(node->left) {
                    q.push(node->left);
                    path.push(tmp + "->" + to_string(node->left->val));
                }
                if(node->right) {
                    q.push(node->right);
                    path.push(tmp + "->" + to_string(node->right->val));
                }
            }
        }
        return ret;
    }
};