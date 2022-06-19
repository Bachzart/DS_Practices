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

/* bfs + hash, AC, but time complexity is O(n^2). */
class Solution {
public:
    unordered_map<long long, int> cnt;
    void bfs(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        long long sum = 0;
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            sum += node->val;
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        cnt[sum]++;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(node->left == nullptr && node->right == nullptr) {
                cnt[node->val]++;
                continue;
            }
            if(node->left != nullptr || node->right != nullptr) bfs(node);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        int maxtimes = 0;
        for(auto &[_, t]: cnt) {
            if(t > maxtimes) maxtimes = t;
        }
        vector<int> ans;
        for(auto &[sum, t]: cnt) {
            if(t == maxtimes) ans.push_back(sum);
        }
        return ans;
    }
};

/* A little simplification. */
class Solution {
public:
    unordered_map<long long, int> cnt;
    int maxtimes = 0;
    void bfs(TreeNode *root) {
        queue<TreeNode*> q;
        q.push(root);
        long long sum = 0;
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            sum += node->val;
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        cnt[sum]++;
        if(cnt[sum] > maxtimes) maxtimes = cnt[sum];
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if(node->left == nullptr && node->right == nullptr) {
                cnt[node->val]++;
                if(cnt[node->val] > maxtimes) maxtimes = cnt[node->val];
                continue;
            }
            if(node->left != nullptr || node->right != nullptr) bfs(node);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        vector<int> ans;
        for(auto &[sum, t]: cnt) {
            if(t == maxtimes) ans.push_back(sum);
        }
        return ans;
    }
};