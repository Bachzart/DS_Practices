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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

/* method 2 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *tmp, *node = q.front(); q.pop();
                tmp = node->left;
                node->left = node->right;
                node->right = tmp;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *tmp, *node = q.front(); q.pop();
            tmp = node->left;
            node->left = node->right;
            node->right = tmp;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};