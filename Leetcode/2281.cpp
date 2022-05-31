/* prefixsum + monotonic stack*/
class Solution {
public:
    const int mod = 1e9 + 7;
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        stack<int> st;
        vector<int> left(n, -1), right(n, n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && strength[st.top()] > strength[i]) {
                right[st.top()] = i;
                st.pop();
            }
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }
        vector<int> psum = strength;
        for(int i = 1; i < n; i++) {
            psum[i] = (psum[i] + psum[i - 1]) % mod;
        }
        vector<int> ppsum = psum;
        for(int i = 1; i < n; i++) {
            ppsum[i] = (ppsum[i] + ppsum[i - 1]) % mod;
        }
        auto f = [&](int l, int r) {
            if(r < 0) return 0;
            if(l < 0) return ppsum[r];
            return (ppsum[r] - ppsum[l] + mod) % mod;
        };
        int ret = 0;
        for(int i = 0; i < n; i++) {
            int l = left[i] + 1, r = right[i] - 1;
            long long sleft = 1ll * f(l - 2, i - 1) * (r - i + 1) % mod;
            long long sright = 1ll * f(i - 1, r) * (i - l + 1) % mod;
            ret += 1ll * strength[i] * (((sright - sleft) + mod) % mod) % mod;
            ret %= mod;
        }
        return ret;
    }
};