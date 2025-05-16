class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        auto f = [&](const string& s1, const string& s2) -> bool {
            if(s1.length() != s2.length())
                return false;
            int differ = 0;
            for(int i = 0; i < s1.length(); ++i) {
                if(s1[i] != s2[i])
                    ++differ;
            }
            return differ == 1;
        };
        int maxSize = 1;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(groups[i] != groups[j] && f(words[i], words[j])) 
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            if(dp[i] > maxSize) 
                maxSize = dp[i];
        } 
        vector<string> ans;
        if(maxSize == 1) {
            ans.push_back(words[0]);
            return ans;
        }
        vector<int> indices;
        int preidx = -1;
        bool first = true;
        for(int i = n - 1; i >= 0; --i) {
            if(dp[i] == maxSize) {
                if(first) {
                    indices.push_back(i);
                    preidx = i;
                    first = false;
                    --maxSize;
                } else {
                    if(f(words[preidx], words[i]) && groups[preidx] != groups[i]) {
                        indices.push_back(i);
                        --maxSize;
                        preidx = i;
                    }
                }
            }
        }
        for(int i = indices.size() - 1; i >= 0; --i)
            ans.push_back(words[indices[i]]);
        return ans;
    }
};