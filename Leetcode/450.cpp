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

/* recursion */
class Solution {
public:
    TreeNode* findmin(TreeNode* root) {
        if(root == nullptr) return nullptr;
        else if(root->left == nullptr) return root;
        else return findmin(root->left);
    }
    TreeNode* findmax(TreeNode* root) {
        if(root == nullptr) return nullptr;
        else if(root->right == nullptr) return root;
        else return findmax(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;
        else if(root->val > key) root->left = deleteNode(root->left, key);
        else if(root->val < key) root->right = deleteNode(root->right, key);
        else {
            TreeNode *pos;
            if(root->left != nullptr) {
                pos = findmax(root->left);
                root->val = pos->val;
                root->left = deleteNode(root->left, root->val);
            } else if(root->right != nullptr) {
                pos = findmin(root->right);
                root->val = pos->val;
                root->right = deleteNode(root->right, root->val);
            } else {
                pos = root;
                if(root->left != nullptr) root = root->right;
                else root = root->left;
                delete pos;
            }
        }
        return root;
    }
};

/* iteration */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *pos = root, *posparent = nullptr;
        if(root == nullptr) return nullptr;
        while(pos != nullptr && pos->val != key) {
            posparent = pos;
            if(pos->val > key) pos = pos->left;
            else pos = pos->right;
        }
        if(pos == nullptr) return root;
        if(pos->left == nullptr && pos->right == nullptr) {
            pos = nullptr;
        } else if(pos->right == nullptr) {
            pos = pos->left;
        } else if(pos->left == nullptr) {
            pos = pos->right;
        } else {
            TreeNode *node = pos->right, *nodeparent = pos;
            while(node->left != nullptr) {
                nodeparent = node;
                node = node->left;
            }
            if(nodeparent->val == pos->val) nodeparent->right = node->right;
            else nodeparent->left = node->right;
            node->right = pos->right;
            node->left = pos->left;
            pos = node;
        }
        if(posparent == nullptr) return pos;
        else {
            if(posparent->left != nullptr && posparent->left->val == key) posparent->left = pos;
            else posparent->right = pos;
            return root;
        }
    }
};