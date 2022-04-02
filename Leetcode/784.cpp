class Solution {
public:
    string tmp;
    void dfs(vector<string>& ret, string s, int first, int length) {
        if(first == length) {
            ret.push_back(s);
            return;
        }
        if(isupper(s[first])) {
            s[first] += 32;
            dfs(ret, s, first + 1, length);
            s[first] -= 32;
        } else if(islower(s[first])) {
            s[frist] -= 32;
            dfs(ret, s, first + 1, length);
            s[first] += 32;
        } else dfs(ret, s, first + 1, length);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ret;
        if(s.length() > 0) dfs(ret, s, 0, s.length());
        return ret;
    }
};