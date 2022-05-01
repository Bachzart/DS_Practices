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
/* dfs */
class Solution {
public:
    int getdepth(TreeNode *root) {
        if(!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left) return getdepth(root->right) <= 1;
        if(!root->right) return getdepth(root->left) <= 1;
        return abs(getdepth(root->left) - getdepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    int getdepth(TreeNode *root) {
        if(!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left) return getdepth(root->right) <= 1;
        if(!root->right) return getdepth(root->left) <= 1;
        if(abs(getdepth(root->left) - getdepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    int getdepth(TreeNode *root) {
        if(!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left) return getdepth(root->right) <= 1 && isBalanced(root->right);
        if(!root->right) return getdepth(root->left) <= 1 && isBalanced(root->left);
        if(abs(getdepth(root->left) - getdepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {
public:
    int getdepth(TreeNode *root) {
        if(!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(getdepth(root->left) - getdepth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

/* another dfs */
class Solution {
public:
    int height(TreeNode *root) {
        if(!root) return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if(leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1) return -1;
        else return max(leftheight, rightheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};

/* bfs */
class Solution {
public:
    int getdepth(TreeNode *root) {
        if(!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(abs(getdepth(node->left) - getdepth(node->right)) > 1) return false;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return true;
    }
};