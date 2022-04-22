/* method 1 */
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.length();
        int pos = 0, maxlen = 0;
        stack<int> st;
        while(pos < n) {
            int depth = 1;
            while(pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            int len = 0;
            bool isfile = false;
            while(pos < n && input[pos] != '\n') {
                if(input[pos] == '.') isfile = true;
                len++;
                pos++;
            }
            pos++;
            while(st.size() >= depth) st.pop();
            if(!st.empty()) len += st.top() + 1;
            if(isfile) maxlen = max(maxlen, len);
            else st.push(len);
        }
        return maxlen;
    }
};

/* method 2 */
class Solution {
public:
    int lengthLongestPath(string input) {
        int n = input.length();
        int pos = 0, maxlen = 0;
        vector<int> level(n + 1);
        while(pos < n) {
            int depth = 1;
            while(pos < n && input[pos] == '\t') {
                pos++;
                depth++;
            }
            int len = 0;
            bool isfile = false;
            while(pos < n && input[pos] != '\n') {
                if(input[pos] == '.') isfile = true;
                len++;
                pos++;
            }
            pos++;
            if(depth > 1) len += level[depth - 1] + 1;
            if(isfile) maxlen = max(maxlen, len);
            else level[depth] = len;
        }
        return maxlen;
    }
};