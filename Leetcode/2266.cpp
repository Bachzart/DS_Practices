class Solution {
public:
    int countTexts(string pressedKeys) {
        int mod = 1e9 + 7;
        int len = pressedKeys.length();
        vector<long long> dp(len);
        dp[0] = 1;
        for(int i = 1; i < len; i++) {
            dp[i] = dp[i - 1];
            if(pressedKeys[i] == pressedKeys[i - 1]) {
                dp[i] += i >= 2 ? dp[i - 2] : 1;
                if(i >= 2 && pressedKeys[i] == pressedKeys[i - 2]) {
                    dp[i] += i >= 3 ? dp[i - 3] : 1;
                    if((pressedKeys[i] == '7' || pressedKeys[i] == '9') && i >= 3 && pressedKeys[i] == pressedKeys[i - 3]) {
                        dp[i] += i >= 4 ? dp[i - 4] : 1; 
                    }
                }
            }
            dp[i] %= mod;
        }
        return dp[len - 1];
    }
};

class Solution {
public:
    int countTexts(string pressedKeys) {
        int mod = 1e9 + 7;
        int len = pressedKeys.length();
        vector<long long> dp(len + 1);
        dp[0] = 1, dp[1] = 1;
        for(int i = 2; i <= len; i++) {
            dp[i] = dp[i - 1];
            if(pressedKeys[i - 1] == pressedKeys[i - 2]) {
                dp[i] += dp[i - 2];
                if(i >= 3 && pressedKeys[i - 1] == pressedKeys[i - 3]) {
                    dp[i] += dp[i - 3];
                    if((pressedKeys[i - 1] == '7' || pressedKeys[i - 1] == '9') && i >= 4 && pressedKeys[i - 1] == pressedKeys[i - 4]) {
                        dp[i] += dp[i - 4]; 
                    }
                }
            }
            dp[i] %= mod;
        }
        return dp[len];
    }
};