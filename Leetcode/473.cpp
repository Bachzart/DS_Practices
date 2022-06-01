/* back tracking + greedy */
class Solution {
public:
    bool dfs(int index, vector<int>& matchsticks, vector<int>& edges, int len) {
        if(index == matchsticks.size()) return true;
        for(int i = 0; i < edges.size(); i++) {
            edges[i] += matchsticks[index];
            if(edges[i] <= len && dfs(index + 1, matchsticks, edges, len)) return true;
            edges[i] -= matchsticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> edges(4);
        return dfs(0, matchsticks, edges, sum / 4);
    }
};

/* dp + states compress */
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;
        int len = sum / 4, n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for(int s = 1; s < (1 << n); s++) {
            for(int k = 0; k < n; k++) {
                if((s & (1 << k)) == 0) continue;
                int s1 = s & ~(1 << k);
                if(dp[s1] >= 0 && dp[s1] + matchsticks[k] <= len) {
                    dp[s] = (dp[s1] + matchsticks[k]) % len;
                    break;
                }
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};