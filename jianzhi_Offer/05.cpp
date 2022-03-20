/* method 1 */
class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') ret += "%20";
            else ret += s[i];
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') s.replace(i, 1, "%20");
        }
        return s;
    }
};