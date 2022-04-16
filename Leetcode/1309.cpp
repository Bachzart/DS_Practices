class Solution {
public:
    string freqAlphabets(string s) {
        string ret;
        int i = 0;
        while(i < s.length()) {
            if(isdigit(s[i])) {
                if(isdigit(s[i + 1]) && s[i + 2] == '#') {
                    ret += ((s[i] - '0') * 10 + (s[i + 1] - '0') + 'a' - 1);
                    i += 3;
                } else {
                    ret += (s[i] - '0' + 'a' - 1);
                    i += 1;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    string freqAlphabets(string s) {
        string ret;
        int i = 0;
        while(i < s.length()) {
            if(i + 2 < s.length() && s[i + 2] == '#') {
                ret += ((s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a');
                i += 3;
            } else {
                ret += (s[i] - '0' - 1 + 'a');
                i += 1;
            }
        }
        return ret;
    }
};