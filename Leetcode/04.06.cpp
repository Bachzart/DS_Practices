/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* method 1: flatting */
class Solution {
    vector<TreeNode*> inorderseq;
    void inorder(TreeNode *root) {
        if(root == nullptr) return;
        inorder(root->left);
        inorderseq.push_back(root);
        inorder(root->right);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root);
        int size = inorderseq.size();
        for(int i = 0; i < size; i++) {
            if(inorderseq[i] == p) {
                if(i == size - 1) return nullptr;
                else return inorderseq[i + 1];
            }
        }
        return nullptr;
    }
};

/* method 2: use stack */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        stack<TreeNode*> st;
        TreeNode *pre;
        while(!st.empty() || root) {
            while(root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(pre == p) return root;
            pre = root;
            root = root->right;
        }
        return nullptr;
    }
};

/* method 3: use binary search properties*/
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root == nullptr) return nullptr;
        TreeNode *pos = nullptr;
        if(p->right != nullptr) {
            pos = p->right;
            while(pos->left != nullptr) pos = pos->left;
            return pos;
        }
        TreeNode *node = root;
        while(node != nullptr) {
            if(node->val > p->val) {
                pos = node;
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return pos;
    }
};