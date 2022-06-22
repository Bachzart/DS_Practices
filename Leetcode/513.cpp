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

/* bfs */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0, tmp = 0, ret = 0;
        while(!q.empty()) {
            queue<TreeNode*> qtmp;
            if(!q.empty()) {
                tmp++;
                if(tmp > depth) ret = q.front()->val;
                while(!q.empty()) {
                    TreeNode *node = q.front(); q.pop();
                    if(node->left != nullptr) qtmp.push(node->left);
                    if(node->right != nullptr) qtmp.push(node->right);
                }
                q = qtmp;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto node = q.front(); q.pop();
                if(i == 0) ret = node->val;
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
        }
        return ret;
    }
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret = 0;
        while(!q.empty()) {
            auto node = q.front(); q.pop();
            if(node->right != nullptr) q.push(node->right);
            if(node->left != nullptr) q.push(node->left);
            ret = node->val;
        }
        return ret;
    }
};

/* dfs */
class Solution {
public:
    int ret, depth = 0;
    void dfs(TreeNode *node, int d) {
        if(node == nullptr) return;
        if(d > depth) {
            depth = d;
            ret = node->val;
        }
        if(node->left != nullptr) dfs(node->left, d + 1);
        if(node->right != nullptr) dfs(node->right, d + 1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ret = root->val;
        dfs(root, 0);
        return ret;
    }
};