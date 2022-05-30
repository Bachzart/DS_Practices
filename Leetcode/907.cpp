/* monotonic stack */
class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> lmin(n, -1), rmin(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) lmin[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) rmin[i] = st.top();
            st.push(i);
        }
        long long ret = 0;
        for(int i = 0; i < n; i++) {
            ret = (ret + ((long long)(i - lmin[i]) * (rmin[i] - i) * arr[i] % mod)) % mod;
        }
        return ret;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> lmin(n, -1), rmin(n, n);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                rmin[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) lmin[i] = st.top();
            st.push(i);
        }
        long long ret = 0;
        for(int i = 0; i < n; i++) {
            ret = (ret + ((long long)(i - lmin[i]) * (rmin[i] - i) * arr[i] % mod)) % mod;
        }
        return ret;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long ret = 0;
        int l, r;
        for(int i = 0; i <= n; i++) {
            int cur = (i == n ? 0 : arr[i]);
            while(!st.empty() && arr[st.top()] > cur) {
                int index = st.top(); st.pop();
                l = index - (st.empty() ? -1 : st.top());
                r = i - index;
                ret = (ret + ((long long)l * r * arr[index])) % mod;
            }
            st.push(i);
        }
        return ret;
    }
};