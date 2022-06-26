/* dp */
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[105][3] = {0};
        dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
        int size = costs.size();
        for(int i = 1; i < size; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        int ans = min(dp[size - 1][0], min(dp[size - 1][1], dp[size - 1][2]));
        return ans;
    }
};

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[105][3] = {0};
        dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
        int size = costs.size();
        for(int i = 1; i < size; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
        }
        return min(dp[size - 1][0], min(dp[size- 1][1], dp[size - 1][2]));
    }
};