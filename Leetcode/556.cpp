/* linear solution */
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();
        if(len == 1) return -1;
        int pos = len - 2;
        while(pos >= 0 && s[pos] >= s[pos + 1]) pos--;
        if(pos < 0) return -1;
        int nextpost = len - 1;
        while(nextpost >= 0 && s[nextpost] <= s[pos]) nextpost--;
        swap(s[pos], s[nextpost]);
        reverse(s.begin() + pos + 1, s.end());
        long long ret = 0;
        for(int i = 0; i < len; i++) {
            ret = ret * 10 + s[i] - '0';
        }
        if(ret > INT_MAX) return -1;
        return ret;
    }
};

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.length();
        if(len == 1) return -1;
        int pos = len - 2;
        while(pos >= 0 && s[pos] >= s[pos + 1]) pos--;
        if(pos < 0) return -1;
        int nextpost = len - 1;
        while(nextpost >= 0 && s[nextpost] <= s[pos]) nextpost--;
        swap(s[pos], s[nextpost]);
        reverse(s.begin() + pos + 1, s.end());
        long long ret = stoll(s);
        if(ret > INT_MAX) return -1;
        return ret;
    }
};