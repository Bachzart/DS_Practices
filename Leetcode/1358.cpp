/*
Method 1: Sliding Window, fix the right point and slide the left point.
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ht[3] = {0};
        int left = 0, ans = 0;
        for(char c: s) {
            ht[c - 'a']++;
            while(ht[0] && ht[1] && ht[2]) {
                ht[s[left] - 'a']--;
                left++;
            }
            ans += left;
        }

        return ans;
    }
};

/*
Method 2: Sliding Window, fix the left point and slide the right point.

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
*/