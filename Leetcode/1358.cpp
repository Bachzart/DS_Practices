class Solution {
public:
    int numberOfSubstrings(string s) {
        int ht[3] = {0};
        int ans = 0, len = s.length();
        int left = 0, right = 0;
        for(; right < len; ++right) {
            ht[s[right] - 'a']++;
            while(ht[0] > 0 && ht[1] > 0 && ht[2] > 0) {
                ans += len - right;
                ht[s[left++] - 'a']--;
            }
        }

        return ans;
    }
};