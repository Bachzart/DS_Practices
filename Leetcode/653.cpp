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
    unordered_set<int> ht;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(ht.find(root->val) != ht.end()) return true;
        else ht.insert(k - root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

/* method 2 */
class Solution {
public:
    unordered_set<int> ht;
    bool findTarget(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(ht.find(node->val) != ht.end()) return true;
            ht.insert(k - node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return false;
    }
};