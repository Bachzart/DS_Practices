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
 * Similar Questions: 560
 */
/*
Method 1: Prefix Sum + DFS
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<long long, int> cnt = {{0, 1}};

        auto dfs = [&](this auto&& dfs, TreeNode* node, long long pathSum) -> void {
            if(node == nullptr) {
                return;
            }
            pathSum += node->val;
            ans += cnt[pathSum - targetSum];

            cnt[pathSum]++;
            dfs(node->left, pathSum);
            dfs(node->right, pathSum);
            cnt[pathSum]--;
        };

        dfs(root, 0);

        return ans;
    }
};