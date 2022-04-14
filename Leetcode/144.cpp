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
    void pre(vector<int>& seq, TreeNode *root) {
        if(!root) return;
        seq.push_back(root->val);
        pre(seq, root->left);
        pre(seq, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        pre(ret, root);
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            if(!st.empty()) {
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return ret;
    }
};

/* method 3 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *p1 = root, *p2;
        while(p1) {
            p2 = p1->left;
            if(p2) {
                while(p2->right && p2->right != p1) p2 = p2->right;
                if(!p2->right) {
                    ret.push_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else p2->right = nullptr;
            } else ret.push_back(p1->val);
            p1 = p1->right;
        }
        return ret;
    }
};