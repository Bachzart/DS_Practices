class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        for(int i = 0; i < len; i++) {
            if(s[i] != ' ') {
                int j;
                for(j = i + 1; j < len; j++) {
                    if(s[j] == ' ') break;
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
        }
        return s;
    }
};