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
/*
Method 2: DFS with back-tracking
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, TreeNode* node, int sum) -> void {
            if(node == nullptr) return;
            path.push_back(node->val);
            sum += node->val;
            if(node->left == nullptr && node->right == nullptr && sum == targetSum) {
                ans.push_back(path);
            } else {
                dfs(node->left, sum);
                dfs(node->right, sum);
            }
            path.pop_back();
        };

        dfs(root, 0);

        return ans;
    }
};

/* 
Method 1: DFS without back-tracking

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        auto dfs = [&](this auto&& dfs, TreeNode* node, vector<int> path, int sum) -> void {
            if(node == nullptr) return;
            if(node->left == nullptr && node->right == nullptr && node->val + sum == targetSum) {
                path.push_back(node->val);
                ans.push_back(path);
                return;
            }
            path.push_back(node->val);
            sum += node->val;
            dfs(node->left, path, sum);
            dfs(node->right, path, sum);
        };

        vector<int> path;
        dfs(root, path, 0);

        return ans;
    }
};

*/