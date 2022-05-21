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

/* bfs + violent solution */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        queue<TreeNode*> q1;
        q1.push(root);
        int cnt = 0;
        while(!q1.empty()) {
            TreeNode *node = q1.front(); q1.pop();
            queue<TreeNode*> q2;
            q2.push(node);
            int sum = 0, nodecnt = 0;
            while(!q2.empty()) {
                TreeNode *tmp = q2.front(); q2.pop();
                sum += tmp->val;
                nodecnt++;
                if(tmp->left) q2.push(tmp->left);
                if(tmp->right) q2.push(tmp->right);
            }
            if(sum / nodecnt == node->val) cnt++;
            if(node->left) q1.push(node->left);
            if(node->right) q1.push(node->right);
        }
        return cnt;
    }
};

/* dfs(preorder) */
class Solution {
public:
    pair<int, int> dfs(TreeNode *root, int &ans) {
        if(root == nullptr) {
            return {0, 0};
        }
        pair<int, int> left, right;
        left = dfs(root->left, ans);
        right = dfs(root->right, ans);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        if(sum / cnt == root->val) ans++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};