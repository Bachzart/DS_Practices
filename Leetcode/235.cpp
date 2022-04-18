/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* method 1 */
class Solution {
public:
    void getpath(TreeNode *root, TreeNode *target, vector<TreeNode*>& path) {
        path.push_back(root);
        if(root == target) return;
        if(root->val > target->val) getpath(root->left, target, path);
        if(root->val < target->val) getpath(root->right, target, path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        getpath(root, p, ppath);
        getpath(root, q, qpath);
        TreeNode *lca;
        int index = 0;
        while(index < ppath.size() && index < qpath.size()) {
            if(ppath[index] == qpath[index]) lca = ppath[index];
            else break;
            index++;
        }
        return lca;
    }
};

class Solution {
public:
    void getpath(TreeNode *root, TreeNode *target, vector<TreeNode*>& path) {
        while(root) {
            path.push_back(root);
            if(root->val == target->val) return;
            else if(root->val > target->val) root = root->left;
            else root = root->right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath;
        getpath(root, p, ppath);
        getpath(root, q, qpath);
        TreeNode *lca;
        int index = 0;
        while(index < ppath.size() && index < qpath.size()) {
            if(ppath[index] == qpath[index]) lca = ppath[index];
            else break;
            index++;
        }
        return lca;
    }
};

/* method 2 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root) {
            if(root->val > p->val && root->val > q->val) root = root->left;
            else if(root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else return root;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qu;
        qu.push(root);
        TreeNode *lca;
        while(!qu.empty()) {
            lca = qu.front(); qu.pop();
            if(lca->val > p->val && lca->val > q->val) qu.push(lca->left);
            else if(lca->val < p->val && lca->val < q->val) qu.push(lca->right);
            else break;
        }
        return lca;
    }
};