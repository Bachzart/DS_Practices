/* method 1 */
class Solution {
public:
	void inorder(vector<int>& seq, TreeNode* root) {
		if(!root) return;
		inorder(seq, root->left);
		seq.push_back(root->val);
		inorder(seq, root->right);
	}
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		inorder(ret, root);
		return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		stack<TreeNode*> st;
		while(root || !st.empty()) {
			while(root) {
				st.push(root);
				root = root->left;
			}
			if(!st.empty()) {
				root = st.top();
				st.pop();
				ret.push_back(root->val);
				root = root->right;
			}
		}
		return ret;
    }
};

/* method 3 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        TreeNode *p1 = root, *p2;
        while(p1) {
            p2 = p1->left;
            if(p2) {
                while(p2->right && p2->right != p1) p2 = p2->right;
                if(!p2->right) {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                } else {
                	ret.push_back(p1->val);
                	p2->right = nullptr;
                }
            } else ret.push_back(p1->val);
            p1 = p1->right;
        }
        return ret;
    }
};