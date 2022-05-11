// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void postorder(TreeNode *root, vector<int>& arr) {
        if(!root) return;
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }
    TreeNode* construct(int lower, int upper, stack<int>& st) {
        if(st.size() == 0 || st.top() < lower || st.top() > upper) return nullptr;
        int val = st.top();
        st.pop();
        TreeNode *root = new TreeNode(val);
        root->right = construct(val, upper, st);
        root->left = construct(lower, val, st);
        return root;
    }
    vector<string> split(const string &str, char dec) {
        int pos = 0;
        int start = 0;
        vector<string> res;
        while(pos < str.length()) {
            while(pos < str.length() && str[pos] == dec) pos++;
            start = pos;
            while(pos < str.length() && str[pos] != dec) pos++;
            if(start < str.length()) {
                res.push_back(str.substr(start, pos - start));
            }
        }
        return res;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        vector<int> arr;
        postorder(root, arr);
        if(arr.size() == 0) return ret;
        for(int i = 0; i < arr.size() - 1; i++) {
            ret.append(to_string(arr[i]) + ",");
        }
        ret.append(to_string(arr.back()));
        return ret;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        vector<string> arr = split(data, ',');
        stack<int> st;
        for(auto &str: arr) {
            st.push(stoi(str));
        }
        return construct(INT_MIN, INT_MAX, st);
    }
};