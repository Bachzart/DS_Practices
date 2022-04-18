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
    bool isleaf(TreeNode *node) {
        return !node->left && !node->right;
    }
    int dfs(TreeNode *root) {
        int ans = 0;
        if(root->left) ans += isleaf(root->left) ? root->left->val : dfs(root->left);
        if(root->right && !isleaf(root->right)) ans += dfs(root->right);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        else return dfs(root);
    }
};

class Solution {
public:
    bool isleaf(TreeNode *node) {
        return node && !node->left && !node->right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + (isleaf(root->left) ? root->left->val : 0);
    }
};

/* method 2 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(!root) return sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(node->left) {
                if(!node->left->left && !node->left->right) sum += node->left->val;
                else q.push(node->left);
            }
            if(node->right) q.push(node->right);
        }
        return sum;
    }
};