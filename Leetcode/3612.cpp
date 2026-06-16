class Solution {
public:
    string processStr(string s) {
        string ans;
        for(char c: s) {
            if(c == '*') {
                if(ans.empty()) continue;
                ans.pop_back();
            } else if(c == '#') {
                ans += ans;
            } else if(c == '%') {
                // reverse(ans.begin(), ans.end());
                ans = string(ans.rbegin(), ans.rend());
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};