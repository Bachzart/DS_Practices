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
Method 3: use recursion
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        auto dfs = [&](this auto&& dfs, TreeNode* root) -> void {
            if(!root || k <= 0) {
                return;
            }
            dfs(root->left);
            if(--k == 0) {
                ans = root->val;
            }
            dfs(root->right);
        };
        dfs(root);
        return ans;
    }
};

/*
Method 2: use inroder traversal without recursion

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int ans = 0;
        while(!st.empty() || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            k--;
            if(!k) {
                ans = root->val;
                break;
            }
            root = root->right;
        }
        return ans;
    }
};

*/

/*
Method 1: get the ordered-sequences by inorder traversal

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        auto dfs = [&inorder](this auto&& dfs, TreeNode* root) -> void {
            if(!root) return;
            dfs(root->left);
            inorder.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);

        return inorder[k - 1];
    }
};
*/