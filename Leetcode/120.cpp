/* bottom-up */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int size = triangle.size();
        for(int i = size - 2; i >= 0; i--) {
            for(int j = 0; j < i; j++) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

/* top-down */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int size = triangle.size();
        for(int i = 1; i < size; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            for(int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        return *min_element(dp[size - 1].begin(), dp[size - 1].end());
    }
};