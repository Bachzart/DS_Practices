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
    bool dfs(TreeNode *root, int targetSum, int sum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val + sum == targetSum) return true;
        return dfs(root->left, targetSum, sum + root->val) || dfs(root->right, targetSum, sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return dfs(root, targetSum, 0);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return targetSum == root->val;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

/* method 2 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        queue<TreeNode*> q;
        queue<int> sum;
        q.push(root);
        sum.push(root->val);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            int tmp = sum.front(); sum.pop();
            if(!node->left && !node->right) {
                if(tmp == targetSum) return true;
                continue;
            }
            if(node->left) {
                q.push(node->left);
                sum.push(node->left->val + tmp);
            }
            if(node->right) {
                q.push(node->right);
                sum.push(node->right->val + tmp);
            }
        }
        return false;
    }
};