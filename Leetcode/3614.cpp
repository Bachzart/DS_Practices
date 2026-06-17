/*
Method 2: calculate the final string length first, and then reverse traversal
*/
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> size(n);
        long long sz = 0;
        for(int i = 0; i < n; ++i) {
            char c = s[i];
            if(c == '*') {
                sz = max(sz - 1, 0LL);
            } else if(c == '#') {
                sz *= 2;
            } else if(c != '%') {
                ++sz;
            }
            size[i] = sz;
        }

        if(k >= size[n - 1]) {
            return '.';
        }

        for(int i = n - 1; ; --i) {
            char c = s[i];
            sz = size[i];
            if(c == '#') {
                if(k >= sz / 2) {
                    k -= sz / 2;
                }
            } else if(c == '%') {
                k = sz - 1 - k;
            } else if(c != '*' && k == sz - 1) {
                return c;
            }
        }
    }
};

/*
Method 1: violent solution, MLE

class Solution {
public:
    char processStr(string s, long long k) {
        string ans("");
        for(char c: s) {
            if(c == '*') {
                if(ans.empty()) continue;
                ans.pop_back();
            } else if(c == '#') {
                ans += ans;
            } else if(c == '%') {
                ranges::reverse(ans);
            } else {
                ans.push_back(c);
            }
        }
        if(k >= ans.length()) return '.';
        return ans[k];
    }
};

*/