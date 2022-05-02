class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        for(int i = 0; i < size; i++) {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a, b, res;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                if(tokens[i] == "+") res = a + b;
                else if(tokens[i] == "-") res = b - a;
                else if(tokens[i] == "*") res = a * b;
                else if(tokens[i] == "/") res = b / a;
                st.push(res);
            } else {
                int tmp = 0, len = tokens[i].length();
                int index = 0, flag = true;
                if(tokens[i][index] == '-') {
                    flag = false;
                    index++;
                }
                while(index < len) {
                    tmp = tmp * 10 + tokens[i][index] - '0';
                    index++;
                }
                if(!flag) tmp = -tmp;
                st.push(tmp);
            }
        }
        return st.top();
    }
};

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int size = tokens.size();
        for(int i = 0; i < size; i++) {
            if(isdigit(tokens[i][0]) || isdigit(tokens[i][1])) {
                st.push(atoi(tokens[i].c_str()));
            } else {
                int a, b;
                a = st.top(); st.pop();
                b = st.top(); st.pop();
                if(tokens[i] == "+") st.push(a + b);
                else if(tokens[i] == "-") st.push(b - a);
                else if(tokens[i] == "*") st.push(a * b);
                else st.push(b / a);
            }
        }
        return st.top();
    }
};