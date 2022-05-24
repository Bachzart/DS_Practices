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
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node->val != value) return false;
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        return true;
    }
};

/* dfs */
class Solution {
public:
    bool dfs(TreeNode* root, int value) {
        if(root == nullptr) return true;
        if(root->val != value) return false;
        return dfs(root->left, value) && dfs(root->right, value);
    }
    bool isUnivalTree(TreeNode* root) {
        int value = root->val;
        return dfs(root, value);
    }
};