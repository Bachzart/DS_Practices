/* method 1: violent solutions */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length(), i, j, k, ret = 0;
        for(i = 0; i < len; i++) {
            string tmp;
            tmp += s[i];
            for(j = i + 1; j < len; j++) {
                if(tmp.find(s[j]) == string::npos) tmp += s[j];
                else break;
            }
            if(tmp.length() > ret) ret = tmp.length();
        }
        return ret;
    }
};

/* method 2: silding window and use a set simulate hashtable to judge whether the char has appeared or not. */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ht;
        int n = s.length();
        int rk = -1, ans = 0;
        for(int i = 0; i < n; i++) {
            if(i != 0) {
                ht.erase(s[i - 1]);
            }
            while(rk + 1 < n && ht.find(s[rk + 1]) == ht.end()) {
                ht.insert(s[rk + 1]);
                rk++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};

/* method 3: silding window */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int start, end, index, ans, l;
        start = end = ans = l = 0;
        while(end < len) {
            char tmp = s[end];
            for(index = start; index < end; index++) {
                if(tmp == s[index]) {
                    start = index + 1;
                    l = end - start;
                    break;
                }
            }
            end++;
            l++;
            ans = max(ans, l);
        }
        return ans;
    }
};