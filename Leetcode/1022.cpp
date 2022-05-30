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
    vector<vector<int>> paths;
    void dfs(TreeNode* node, vector<int> path) {
        if(node->left == nullptr && node->right == nullptr) {
            path.push_back(node->val);
            paths.push_back(path);
            return;
        }
        path.push_back(node->val);
        if(node->left != nullptr) dfs(node->left, path);
        if(node->right != nullptr) dfs(node->right, path);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        int sum = 0;
        for(int i = 0; i < paths.size(); i++) {
            for(int j = paths[i].size() - 1; j >= 0; j--) {
                if(paths[i][j] == 1) {
                    sum += pow(2, paths[i].size() - 1 - j);
                }
            }
        }
        return sum;
    }
};

class Solution {
public:
    vector<vector<int>> paths;
    void dfs(TreeNode* node, vector<int> path) {
        if(node->left == nullptr && node->right == nullptr) {
            path.push_back(node->val);
            paths.push_back(path);
            return;
        }
        path.push_back(node->val);
        if(node->left != nullptr) dfs(node->left, path);
        if(node->right != nullptr) dfs(node->right, path);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        int sum = 0;
        for(int i = 0; i < paths.size(); i++) {
            for(int j = paths[i].size() - 1; j >= 0; j--) {
                if(paths[i][j] == 1) {
                    sum += 1 << (paths[i].size() - 1 - j);
                }
            }
        }
        return sum;
    }
};

class Solution {
public:
    int dfs(TreeNode* node, int tmp) {
        if(node == nullptr) return 0;
        tmp = (tmp << 1) | node->val;
        if(node->left == nullptr && node->right == nullptr) return tmp;
        return dfs(node->left, tmp) + dfs(node->right, tmp);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};

class Solution {
public:
    int ret = 0;
    void dfs(TreeNode* node, int tmp) {
        if(node == nullptr) return;
        tmp = tmp * 2 + node->val;
        if(node->left == nullptr && node->right == nullptr) {
            ret += tmp;
            return;
        }
        dfs(node->left, tmp);
        dfs(node->right, tmp);
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
};

/* postorder recursion */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        stack<TreeNode*> st;
        int val = 0, ret = 0;
        TreeNode *pre = nullptr;
        while(root != nullptr || !st.empty()) {
            while(root != nullptr) {
                val = (val << 1) | root->val;
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if(root->right == nullptr || root->right == pre) {
                if(root->left == nullptr && root->right == nullptr) ret += val;
                val >>= 1;
                st.pop();
                pre = root;
                root = nullptr;
            } else root = root->right;
        }
        return ret;
    }
};

/* bfs */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 0);
        int ret = 0;
        while(!q.empty()) {
            auto [node, val] = q.front(); q.pop();
            if(node->left == nullptr && node->right == nullptr) {
                ret += val << 1 | node->val;
            }
            if(node->left != nullptr) {
                q.emplace(node->left, val << 1 | node->val);
            }
            if(node->right != nullptr) {
                q.emplace(node->right, val << 1 | node->val);
            }
        }
        return ret;
    }
};