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
/**
 * Similiar Questions: 543
 * */
/*
Method 1: DFS
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> int {
            if(node == nullptr) {
                return 0;
            }
            int left = dfs(node->left);
            int right = dfs(node->right);
            ans = max(ans, left + right + node->val);
            return max(max(left, right) + node->val, 0);
        };
        dfs(root);
        
        return ans;
    }
};