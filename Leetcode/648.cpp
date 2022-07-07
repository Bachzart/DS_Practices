/* violent solution */
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        auto isroot = [](string &s, string &root) -> bool {
            if(root.length() > s.length()) return false;
            else {
                for(int i = 0; i < root.length(); i++) {
                    if(root[i] != s[i]) return false;
                }
                return true;
            }
        };
        int len = sentence.length(), i = 0;
        string tmp, ret;
        while(i <= len) {
            if(sentence[i] == ' ' || i == len) {
                string min_root = "";
                bool flag = false;
                for(auto &s: dictionary) {
                    if(isroot(tmp, s)) {
                        if(min_root != "" && min_root.length() > s.length()) {
                            min_root = s;
                        } else if(min_root == "") min_root = s;
                        flag = true;
                    }
                }
                if(flag) ret += min_root;
                else ret += tmp;
                if(i < len) ret.push_back(' ');
                tmp = "";
            } else tmp.push_back(sentence[i]);
            i++;
        }
        return ret;
    }
};