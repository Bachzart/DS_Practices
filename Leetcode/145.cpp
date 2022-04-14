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
    void postorder(vector<int>& seq, TreeNode* root) {
        if(!root) return;
        postorder(seq, root->left);
        postorder(seq, root->right);
        seq.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(ret, root);
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st1, st2;
        while(root || !st1.empty()) {
            while(root) {
                st1.push(root);
                st2.push(root);
                root = root->right;
            }
            if(!st1.empty()) {
                root = st1.top();
                st1.pop();
                root = root->left;
            }
        }
        while(!st2.empty()) {
            ret.push_back(st2.top()->val);
            st2.pop();
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        TreeNode *pre = nullptr;
        while(root || !st.empty()) {
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(!root->right || root->right == pre) {
                ret.push_back(root->val);
                pre = root;
                root = nullptr;
            } else {
                st.push(root);
                root = root->right;
            }
        }
        return ret;
    }
};

/* method 3 */
class Solution {
public:
    void addpath(vector<int>& seq, TreeNode *node) {
        int cnt = 0;
        while(node) {
            cnt++;
            seq.push_back(node->val);
            node = node->right;
        }
        reverse(seq.end() - cnt, seq.end());
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *p1 = root, *p2;
        while(p1) {
            p2 = p1->left;
            if(p2) {
                while(p2->right && p2->right != p1) p2 = p2->right;
                if(!p2->right) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                    p2->right = nullptr;
                    addpath(ret, p1->left);
                }
            }
            p1 = p1->right;
        }
        addpath(ret, root);
        return ret;
    }
};