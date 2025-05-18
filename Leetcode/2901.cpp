class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> pre_idx(n, -1);
        auto f = [&](const string& s1, const string& s2) -> bool {
            if(s1.length() != s2.length())
                return false;
            int differ = 0;
            for(int i = 0; i < s1.length(); ++i) {
                if(s1[i] != s2[i])
                    ++differ;
                if(differ > 1)
                    return false;
            }
            return differ == 1;
        };
        int last_idx = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(f(words[i], words[j]) && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                    pre_idx[i] = j;
                }
            }
            if(dp[i] > dp[last_idx]) 
                last_idx = i;
        } 
        vector<string> ans;
        for(int i = last_idx; i >= 0; i = pre_idx[i]) 
            ans.emplace_back(words[i]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};