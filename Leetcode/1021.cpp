/* count amount */
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt1 = 0, cnt2 = 0, pos = 0;
        int len = s.length();
        string ret = "";
        for(int i = 0; i < len; i++) {
            if(s[i] == '(') cnt1++;
            if(s[i] == ')') cnt2++;
            if(cnt1 == cnt2) {
                cnt1 = cnt2 = 0;
                ret += s.substr(pos + 1, i - pos - 1);
                pos = i + 1;
            }
        }
        return ret;
    }
};

/* use stack */
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ret;
        stack<char> st;
        for(char c: s) {
            if(c == ')') st.pop();
            if(!st.empty()) ret.push_back(c);
            if(c == '(') st.push_back(c);
        }
        return ret;
    }
};