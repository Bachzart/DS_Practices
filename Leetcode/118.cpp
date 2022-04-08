class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        int dp[31][31] = {0};
        dp[0][0] = 1;
        ret.push_back({dp[0][0]});
        for(int i = 1; i < numRows; i++) {
            vector<int> tmp;
            dp[i][0] = dp[i - 1][0];
            tmp.push_back(dp[i][0]);
            for(int j = 1; j < i; j++) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                tmp.push_back(dp[i][j]);
            }
            dp[i][i] = dp[i - 1][i - 1];
            tmp.push_back(dp[i][i]);
            ret.push_back(tmp);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for(int i = 0; i < numRows; i++) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for(int j = 1; j < i; j++) {
                ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};