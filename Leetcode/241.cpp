class Solution {
public:
    vector<int> dfs(vector<vector<vector<int>>>& dp, int l, int r, const vector<int>& ops) {
        if(dp[l][r].empty()) {
            if(l == r) dp[l][r].push_back(ops[l]);
            else {
                for(int i = l; i < r; i += 2) {
                    auto left = dfs(dp, l, i, ops);
                    auto right = dfs(dp, i + 2, r, ops);
                    for(auto& lv: left) {
                        for(auto& rv: right) {
                            if(ops[i + 1] == ADDTION) dp[l][r].push_back(lv + rv);
                            else if(ops[i + 1] == SUBTRACTION) dp[l][r].push_back(lv - rv);
                            else dp[l][r].push_back(lv * rv);
                        }
                    }
                }
            }
        }
        return dp[l][r];
    }
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ops;
        for(int i = 0; i < expression.length(); ) {
            if(!isdigit(expression[i])) {
                if(expression[i] == '+') ops.push_back(ADDTION);
                else if(expression[i] == '-') ops.push_back(SUBTRACTION);
                else ops.push_back(MULTIPLICATION);
                i++;
            } else {
                int t = 0;
                while(i < expression.length() && isdigit(expression[i])) {
                    t = t * 10 + expression[i] - '0';
                    i++;
                }
                ops.push_back(t);
            }
        }
        vector<vector<vector<int>>> dp(ops.size(), vector<vector<int>>(ops.size()));
        return dfs(dp, 0, ops.size() - 1, ops);
    }
private:
    const int ADDTION = -1;
    const int SUBTRACTION = -2;
    const int MULTIPLICATION = -3;
};