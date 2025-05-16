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
        vector<int> indices;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if(groups[i] != groups[j] && f(words[i], words[j])) 
                    if(dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        indices.push_back(j);
                    }
            }
            if(dp[i] > maxSize) 
                maxSize = dp[i];
        } 
        for_each(indices.begin(), indices.end(), [&](int i) {
            cout << i << ' ';
        });
        cout << endl;
        vector<string> ans;
        if(maxSize == 1) {
            ans.push_back(words[0]);
            return ans;
        }
        for(int i: indices) {
            ans.push_back(words[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            if(maxSize == dp[i]) {
                ans.push_back(words[i]);
                break;
            }
        }
        return ans;
    }
};