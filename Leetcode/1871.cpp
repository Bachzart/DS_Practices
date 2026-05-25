class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.length();
        if(s[len - 1] != '0') return false;

        vector<bool> dp(len, false);
        dp[0] = true;
        int cnt = 0;
        for(int i = 1; i < len; ++i) {
            if(i - maxJump > 0) {
                cnt -= dp[i - maxJump - 1];
            }
            if(i - minJump >= 0) {
                cnt += dp[i - minJump];
            }
            if(s[i] == '0' && cnt > 0) {
                dp[i] = true;
            }
        }
        return dp[len - 1];
    }
};
