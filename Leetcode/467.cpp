/* dp + string */
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int len = p.length(), k = 1;
        for(int i = 0; i < len; i++) {
            if(i > 0 && (p[i] - p[i - 1] + 26) % 26 == 1) k++;
            else k = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};