/*
method 1: dp
*/
class Solution {
public:
	const int MOD = 1e9 + 7;
    int numTilings(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        dp[0][3] = 1;
        for(int i = 1; i <= n; ++i) {
        	dp[i][0] = dp[i - 1][3];
        	dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        	dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        	dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        return dp[n][3];
    }
};

/*
0 0 0 1 
1 0 0 1 
1 1 1 2 
2 2 2 5 
5 4 4 11 

*/