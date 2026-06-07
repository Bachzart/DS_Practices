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
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodeMap;
        unordered_set<int> children;
        for(auto& v: descriptions) {
            int p = v[0], c = v[1], isLeft = v[2];
            children.insert(c);
            if(!nodeMap.count(p)) nodeMap[p] = new TreeNode(p);
            if(!nodeMap.count(c)) nodeMap[c] = new TreeNode(c);

            isLeft ? nodeMap[p]->left = nodeMap[c] : nodeMap[p]->right = nodeMap[c];
        }

        for(auto& v: descriptions) {
            if(!children.count(v[0])) {
                return nodeMap[v[0]];
            }
        }
        return nullptr;
    }
};