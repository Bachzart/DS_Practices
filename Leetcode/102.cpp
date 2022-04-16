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

/* method 1 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        int cnt = 1;
        while(!q.empty()) {
            vector<int> tmp;
            TreeNode *node;
            int sum = 0;
            for(int i = 0; i < cnt; i++) {
                node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                    sum++;
                }
                if(node->right) {
                    q.push(node->right);
                    sum++;
                }
            }
            cnt = sum;
            ret.push_back(tmp);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> tmp;
            TreeNode *node;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    void dfs(vector<vector<int>>& ret, TreeNode *root, int level) {
        if(ret.size() < level + 1) ret.push_back(vector<int>());
        ret[level].push_back(root->val);
        if(root->left) dfs(ret, root->left, level + 1);
        if(root->right) dfs(ret, root->right, level + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        dfs(ret, root, 0);
        return ret;
    }
};