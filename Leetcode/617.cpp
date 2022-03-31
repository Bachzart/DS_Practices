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

/* dfs */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        TreeNode* merged_node = new TreeNode(root1->val + root2->val);
        merged_node->left = mergeTrees(root1->left, root2->left);
        merged_node->right = mergeTrees(root1->right, root2->right);
        return merged_node;
    }
};

/* bfs */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        TreeNode* merged_node = new TreeNode(root1->val + root2->val);
        queue<TreeNode*> q, q1, q2;
        q.push(merged_node);
        q1.push(root1);
        q2.push(root2);
        while(!q1.empty() && !q2.empty()) {
            auto node = q.front(), node1 = q1.front(), node2 = q2.front();
            q.pop(), q1.pop(), q2.pop();
            auto left1 = node1->left, left2 = node2->left;
            auto right1 = node1->right, right2 = node2->right;
            if(left1 != nullptr || left2 != nullptr) {
                if(left1 != nullptr && left2 != nullptr) {
                    auto left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    q.push(left);
                    q1.push(left1);
                    q2.push(left2);
                } else if(left1 != nullptr) {
                    node->left = left1;
                } else if(left2 != nullptr) {
                    node->left = left2;
                }
            }
            if(right1 != nullptr || right2 != nullptr) {
                if(right1 != nullptr && right2 != nullptr) {
                    auto right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    q.push(right);
                    q1.push(right1);
                    q2.push(right2);
                } else if(right1 != nullptr) {
                    node->right = right1;
                } else if(right2 != nullptr) {
                    node->right = right2;
                }
            }
        }
        return merged_node;
    }
};