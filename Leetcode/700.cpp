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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root || root->val == val) return root;
        else if(root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};

/* method 2 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(node->val == val) return node;
            else if(node->val > val && node->left) q.push(node->left);
            else if(node->val < val && node->right) q.push(node->right);
        }
        return nullptr;
    }
};

/* method 3 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return root;
        while(root) {
            if(root->val == val) return root;
            else if(root->val > val) root = root->left;
            else root = root->right;
        }
        return nullptr;
    }
};