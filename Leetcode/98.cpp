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
    bool judge(TreeNode *root, long long lower, long long upper) {
        if(!root) return true;
        if(root->val <= lower || root->val >= upper) return false;
        return judge(root->left, lower, root->val) && judge(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return judge(root, LONG_MIN, LONG_MAX);
    }
};

/* method 2 */
class Solution {
public:
    void inorder(TreeNode *root, vector<int>& v) {
        if(!root) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> tmp;
        inorder(root, tmp);
        for(int i = 0; i < tmp.size() - 1; i++) {
            if(tmp[i + 1] <= tmp[i]) return false;
        }
        return true;
    }
};