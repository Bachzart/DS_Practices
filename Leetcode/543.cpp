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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> depth = [&](TreeNode* root) -> int {
            if(root == nullptr)
                return 0;
            int L = depth(root->left);
            int R = depth(root->right);
            ans = max(ans, L + R);
            return max(L, R) + 1;
        };
        depth(root);
        return ans;
    }
};



/*
method 2: use Problem 104 solutions

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
            if(root == nullptr)
                return;
            int L = maxDepth(root->left);
            int R = maxDepth(root->right);
            ans = max(ans, L + R);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
*/