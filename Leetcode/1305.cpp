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
    vector<int> ret;
    void preorder(TreeNode *root) {
        if(!root) return;
        ret.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        preorder(root1), preorder(root2);
        sort(ret.begin(), ret.end());
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    void inorder(TreeNode *root, vector<int>& seq) {
        if(!root) return;
        inorder(root->left, seq);
        seq.push_back(root->val);
        inorder(root->right, seq);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2, ret;
        inorder(root1, t1), inorder(root2, t2);
        int p1 = 0, p2 = 0;
        while(p1 < t1.size() && p2 < t2.size()) {
            if(t1[p1] <= t2[p2]) ret.push_back(t1[p1++]);
            else ret.push_back(t2[p2++]);
        }
        while(p1 < t1.size()) ret.push_back(t1[p1++]);
        while(p2 < t2.size()) ret.push_back(t2[p2++]);
        return ret;
    }
};

class Solution {
public:
    void inorder(TreeNode *root, vector<int>& seq) {
        if(!root) return;
        inorder(root->left, seq);
        seq.push_back(root->val);
        inorder(root->right, seq);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2, ret;
        inorder(root1, t1), inorder(root2, t2);
        int p1 = 0, p2 = 0;
        while(p1 < t1.size() && p2 < t2.size()) {
            if(t1[p1] <= t2[p2]) ret.push_back(t1[p1++]);
            else ret.push_back(t2[p2++]);
        }
        if(p1 == t1.size()) ret.insert(ret.end(), t2.begin() + p2, t2.end());
        if(p2 == t2.size()) ret.insert(ret.end(), t1.begin() + p1, t1.end());        
        return ret;
    }
};