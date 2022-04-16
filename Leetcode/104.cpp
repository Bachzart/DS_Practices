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
    void dfs(TreeNode *root, int depth, int &maxdepth) {
        if(!root) return;
        if(depth > maxdepth) maxdepth = depth;
        dfs(root->left, depth + 1, maxdepth);
        dfs(root->right, depth + 1, maxdepth);
    }
    int maxDepth(TreeNode* root) {
        int maxdepth = 0;
        dfs(root, 1, maxdepth);
        return maxdepth;
    }
};

class Solution {
public:
    void dfs(TreeNode *root, int depth, int &maxdepth) {
        if(depth > maxdepth) maxdepth = depth;
        if(root->left) dfs(root->left, depth + 1, maxdepth);
        if(root->right) dfs(root->right, depth + 1, maxdepth);
    }
    int maxDepth(TreeNode* root) {
        int maxdepth = 0;
        if(root) dfs(root, 1, maxdepth);
        return maxdepth;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        else return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/* method 2 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxdepth = 0;
        if(!root) return maxdepth;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node;
            int cnt = q.size();
            for(int i = 0; i < cnt; i++) {
                node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            maxdepth++;
        }
        return maxdepth;
    }
};
