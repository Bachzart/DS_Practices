/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* violent simulate, TLE */
class Solution {
public:
    void inorder(vector<int>& seq, TreeNode *root) {
        if(!root) return;
        inorder(seq, root->left);
        seq.push_back(root->val);
        inorder(seq, root->right);
    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        vector<int> seq;
        inorder(seq, root);
        unordered_map<int, int> ht;
        for(int i = 0; i < ops.size(); i++) {
            int type = ops[i][0], x = ops[i][1], y = ops[i][2];
            for(int i = 0; i < seq.size(); i++) {
                if(x <= seq[i] && seq[i] <= y) ht[seq[i]] = type;
            }
        }
        int redcnt = 0;
        for(auto it: ht) {
            if(it.second == 1) redcnt++;
        }
        return redcnt;
    }
};

/* reverse thinking and simulate, AC, O(nqlogn). */
class Solution {
public:
    set<int> s;
    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        dfs(root);
        int cnt = 0;
        for(int i = ops.size() - 1; i >= 0; i--) {
            int type = ops[i][0], x = ops[i][1], y = ops[i][2];
            while(true) {
                auto it = s.lower_bound(x);
                if(it == s.end() || *it > y) break;
                s.erase(it);
                if(type == 1) cnt++;
            }
        }
        return cnt;
    }
};