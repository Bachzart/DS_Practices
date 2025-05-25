class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> cnt;
        for(const string& w: words)
            ++cnt[w];
        int ans = 0;
        bool mid = false;
        for(auto &[w, t]: cnt) {
            string s = string(w.rbegin(), w.rend());
            if(w == s) {
                if(t % 2 == 1)
                    mid = true;
                ans += 2 * (t / 2 * 2);
            } else if(w > s) {
                ans += 4 * min(cnt[w], cnt[s]);
            }
        }
        if(mid)
            ans += 2;
        return ans;
    }
};