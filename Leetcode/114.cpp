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
/*
Method 4: Morris traversal
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        auto cur = root;
        while(cur != nullptr) {
            if(cur->left != nullptr) {
                auto nxt = cur->left;
                auto pre = nxt;
                while(pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->left = nullptr;
                cur->right = nxt;
            }
            cur = cur->right;
        }
    }
};

/*
Method 3: divide and conquer

class Solution {
public:
    void flatten(TreeNode* root) {
        auto dfs = [](this auto&& dfs, TreeNode* node) -> TreeNode* {
            if(node == nullptr) {
                return nullptr;
            }
            TreeNode* left_tail = dfs(node->left);
            TreeNode* right_tail = dfs(node->right);
            if(left_tail) {
                left_tail->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }
            return right_tail ? right_tail : left_tail ? left_tail: node;
        };
        dfs(root);
    }
};
*/

/*
Method 2: use recursion, right -> left -> root

class Solution {
    TreeNode* head = nullptr;
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};
*/

/*
Method 1: use extra storage

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        auto dfs = [&](this auto&& dfs, TreeNode* node) -> void {
            if(node == nullptr) {
                return;
            }
            nodes.push_back(node);
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        for(int i = 0; i < nodes.size(); ++i) {
            nodes[i]->left = nullptr;
            if(i == nodes.size() - 1) {
                nodes[i]->right = nodes[i]->left;
            } else {
                nodes[i]->right = nodes[i + 1];
            }
        }
    }
};

*/