/* dp */
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[0][0] = (s[0] == '1');
        dp[0][1] = (s[0] == '0');
        for(int i = 1; i < n; i++) {
            dp[i][0] = dp[i - 1][0] + (s[0] == '1');
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[0] == '0');
        }
        return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

/* dp simplification */
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for(char c: s) {
            int newdp0 = dp0, newdp1 = min(dp0, dp1);
            if(c == '1') newdp0++;
            else newdp1++;
            dp0 = newdp0;
            dp1 = newdp1;
        }
        return min(dp0, dp1);
    }
};

/* prefixsum */
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
    }
};