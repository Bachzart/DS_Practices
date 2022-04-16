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
    bool check(TreeNode *root1, TreeNode *root2) {
        if(!root1 && !root2) return true;
        else if(!root1 || !root2) return false;
        else return root1->val == root2->val && check(root1->left, root2->right) && check(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left, root->right);
    }
};

/* method 2 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        TreeNode *u, *v;
        while(!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if(!u && !v) continue;
            if((!u || !v) || (u->val != v->val)) return false;
            q.push(u->left);
            q.push(v->right);
            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }
};