/*
method 1: greddy
*/
class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long ans = 0;
        for(int i = 1; i < n; ++i) {
            if(s[i] != s[i - 1])
                ans += min(i, n - i);
        }
        return ans;
    }
};

/*
method 2: dp

class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        vector<vector<long long>> suf(n + 1, vector<long long>(2, 0));
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] == '1') {
                suf[i][1] = suf[i + 1][1];
                suf[i][0] = suf[i + 1][1] + (n - i);
            } else {
                suf[i][1] = suf[i + 1][0] + (n - i);
                suf[i][0] = suf[i + 1][0];
            }
        }
        vector<long long> pre(2);
        long long res = 1e18;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1')
                pre[0] = pre[1] + i + 1;
            else
                pre[1] = pre[0] + i + 1;
            res = min(res, min(pre[0] + suf[i + 1][0], pre[1] + suf[i + 1][1]));
        }
        return res;
    }
};

*/