/* method 1 */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.length();
        vector<int> ret(len);
        set<int> indices;
        for(int i = 0; i < len; i++) {
            if(s[i] == c) {
                ret[i] = 0;
                indices.insert(i);
            }
        }
        for(int i = 0; i < len; i++) {
            if(s[i] != c) {
                set<int>::iterator it = indices.begin();
                int min = abs(i - *it);
                it++;
                for(; it != indices.end(); it++) {
                    if(abs(i - *it) < min) min = abs(i - *it);
                }
                ret[i] = min;
            }
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.length(), idx;
        vector<int> ret(len);
        for(int i = 0, idx = -len; i < len; i++) {
            if(s[i] == c) idx = i;
            ret[i] = i - idx;
        }
        for(int i = len - 1, idx = 2 * len; i >= 0; i--) {
            if(s[i] == c) idx = i;
            ret[i] = min(ret[i], idx - i);
        }
        return ret;
    }
};