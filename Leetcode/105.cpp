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
Method 3: use recursion and hashmap
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> indices;
        for(int i = 0; i < n; ++i) {
            indices[inorder[i]] = i;
        }

        auto dfs = [&](this auto&& dfs, int pre_l, int pre_r, int in_l) -> TreeNode* {
            if(pre_l == pre_r) {
                return nullptr;
            }
            int left_size = indices[preorder[pre_l]] - in_l;
            TreeNode* left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l);
            TreeNode* right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0);
    }
};

/*
Method 2: use recursion

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) {
            return nullptr;
        }
        int left_size = ranges::find(inorder, preorder[0]) - inorder.begin();
        vector<int> pre1(preorder.begin() + 1, preorder.begin() + 1 + left_size);
        vector<int> pre2(preorder.begin() + 1 + left_size, preorder.end());
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + 1 + left_size, inorder.end());
        TreeNode* left = buildTree(pre1, in1);
        TreeNode* right = buildTree(pre2, in2);
        return new TreeNode(preorder[0], left, right);
    }
};

*/

/*
Method 1: use recursion and span container

class Solution {
    TreeNode* build(span<int> preorder, span<int> inorder) {
        if(preorder.empty()) {
            return nullptr;
        }
        int left_size = ranges::find(inorder, preorder[0]) - inorder.begin();
        TreeNode* left = build(preorder.subspan(1, left_size), inorder.subspan(0, left_size));
        TreeNode* right =build(preorder.subspan(1 + left_size), inorder.subspan(1 + left_size));
        return new TreeNode(preorder[0], left, right);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
};

*/