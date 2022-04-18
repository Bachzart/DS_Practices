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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
};

/* method 2 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(node->val > val) {
                if(node->left) q.push(node->left);
                else {
                    node->left = new TreeNode(val);
                    break;
                }
            } else {
                if(node->right) q.push(node->right);
                else {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

/* method 3 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode *tmp = root;
        while(root) {
            if(root->val > val) {
                if(root->left) root = root->left;
                else {
                    root->left = new TreeNode(val);
                    break;
                }
            } else {
                if(root->right) root = root->right;
                else {
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        return tmp;
    }
};