/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Method 2: Another DFS
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) {
            return root;
        }
        return left ? left : right;
    }
};

/*
Method 1: DFS

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pPath, qPath;
        vector<TreeNode*> path;
        auto getPath = [&](this auto&& getPath, TreeNode* node) -> void {
            if(node == nullptr) {
                return;
            }
            path.push_back(node);
            if(node == p) {
                pPath = path;
            }
            if(node == q) {
                qPath = path;
            }
            getPath(node->left);
            getPath(node->right);
            path.pop_back();
        };

        getPath(root);

        int i = 0;
        while(i < pPath.size() && i < qPath.size() && pPath[i] == qPath[i])
            ++i;

        return pPath[i - 1];
    }
};
*/