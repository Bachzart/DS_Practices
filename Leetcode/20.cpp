class Solution {
public:
    bool isValid(string s) {
		if(s.length() % 2) return false;
		stack<char> st;
		bool flag = true;
		for(char ch: s) {
			if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
			else if(!st.empty()) {
				char tmp = st.top();
				if(ch == ')' && tmp == '(') st.pop();
				else if(ch == ']' && tmp == '[') st.pop();
				else if(ch == '}' && tmp == '{') st.pop();
				else flag = false;
			} else flag = false;
		}
		if(st.empty() && flag) return true;
		else return false;
    }
};