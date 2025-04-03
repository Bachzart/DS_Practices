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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> deal = [&](int left, int right) -> TreeNode* {
            if(left > right)
                return nullptr;
            int mid = left + (right - left) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = deal(left, mid - 1);
            root->right = deal(mid + 1, right);
            return root;
        };
        return deal(0, nums.size() - 1);
    }
};