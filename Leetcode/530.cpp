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

/* violent solution. */
class Solution {
public:
    vector<int> seq;
    void inorder(TreeNode *root) {
        if(root == nullptr) return;
        inorder(root->left);
        seq.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int min_diff = INT_MAX;
        for(int i = 1; i < seq.size(); i++) {
            min_diff = min(min_diff, seq[i] - seq[i - 1]);
        }
        return min_diff;
    }
};

/* inorder */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int min_diff = INT_MAX;
        for(int i = 1; i < seq.size(); i++) {
            min_diff = min(min_diff, seq[i] - seq[i - 1]);
        }
        return min_diff;
    }
};