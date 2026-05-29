class Solution {
    struct Node {
        Node* son[26]{};
        int min_len = INT_MAX;
        int best_idx;

        ~Node() {
            for(Node* s: son) {
                delete s;
            }
        }
    };
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node root{};
        for(int i = 0; i < wordsContainer.size(); ++i) {
            auto& s = wordsContainer[i];
            int len = s.length();
            if(len < root.min_len) {
                root.min_len = len;
                root.best_idx = i;
            }

            Node* cur = &root;
            for(int j = len - 1; j >= 0; --j) {
                int b = s[j] - 'a';
                if(cur->son[b] == nullptr) {
                    cur->son[b] = new Node();
                }
                cur = cur->son[b];
                if(len < cur->min_len) {
                    cur->min_len = len;
                    cur->best_idx = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        for(auto& s: wordsQuery) {
            Node* cur = &root;
            for(int j = s.length() - 1; j >= 0 && cur->son[s[j] - 'a']; --j) {
                cur = cur->son[s[j] - 'a'];
            }
            ans.push_back(cur->best_idx);
        }
        
        return ans;
    }
};