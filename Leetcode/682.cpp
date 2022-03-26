/* method 1: use stack */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int size = ops.size();
        for(int i = 0; i < size; i++) {
            if(ops[i] == "D") {
                int tmp = st.top();
                tmp *= 2;
                st.push(tmp);
            } else if(ops[i] == "C") {
                st.pop();
            } else if(ops[i] == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(a);
                st.push(b);
                st.push(a + b);
            } else {
                int tmp = stoi(ops[i]);
                cout << tmp << ' ' << st.size() << endl;
                st.push(tmp);
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};

/*method 2: use vector to simulate stack */
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int size = ops.size(), tmp, sum = 0;
        for(int i = 0; i < size; i++) {
            int n = scores.size();
            if(ops[i] == "D") {
                tmp = 2 * scores[n - 1];
                sum += tmp;
                scores.push_back(tmp);
            } else if(ops[i] == "C") {
                sum -= scores[n - 1];
                scores.pop_back();
            } else if(ops[i] == "+") {
                tmp = scores[n - 1] + scores[n - 2];
                sum += tmp;
                scores.push_back(tmp);
            } else {
                tmp = stoi(ops[i]);
                sum += tmp;
                scores.push_back(tmp);
            }
        }
        return sum;
    }
};