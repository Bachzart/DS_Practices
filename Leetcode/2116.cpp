class Solution {
public:
    bool canBeValid(string s, string locked) {
        int slen = s.length();
        if(slen & 1) return false;
        stack<char> st;
        for(int i = 0; i < slen; ++i) {
            if(s[i] == '(' || (st.empty() && locked[i] == '0'))
                st.push('(');
            else {
                if(st.empty()) {
                    cout << "a " << i << endl;
                    return false;
                }
                if(!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    cout << "b " << i << endl;
                    return false;
                }
            }
        }
        return st.empty();
    }
};