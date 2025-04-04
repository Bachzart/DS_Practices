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
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        function<pair<TreeNode*, int>(TreeNode*)> f = [&](TreeNode* root) -> pair<TreeNode*, int> {
            if(root == nullptr)
                return {root, 0};
            auto left = f(root->left);
            auto right = f(root->right);
            if(left.second > right.second)
                return {left.first, left.second + 1};
            if(left.second < right.second)
                return {right.first, right.second + 1};
            return {root, left.second + 1};
        };
        return f(root).first;
    }
};