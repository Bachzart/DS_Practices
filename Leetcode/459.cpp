/* method 1: violent solution */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int i = 1; i <= len / 2; i++) {
            if(len % i == 0) {
                for(int j = 0; j < len - i; j += i) {
                    string tmp = s.substr(j, i), t;
                    while(t.length() < len) t += tmp;
                    if(t == s) return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int i = 1; i <= len / 2; i++) {
            if(len % i == 0) {
                bool match = true;
                for(int j = i; j < len; j++) {
                    if(s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if(match) return true;
            }
        }
        return false;
    }
};

/* method 2 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.length();
    }
};