/* dp + string */
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for(char a = 'a'; a <= 'z'; a++) {
            for(char b = 'a'; b <= 'z'; b++) {
                if(a == b) continue;
                int diff = 0, diff_with_b = -s.length();
                for(char c: s) {
                    if(c == a) {
                        diff++;
                        diff_with_b++;
                    } else if(c == b) {
                        diff_with_b = --diff;
                        diff = max(diff, 0);
                    }
                    ans = max(ans, diff_with_b);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        int diff[26][26] = {0}, diff_with_b[26][26];
        memset(diff_with_b, 0x80, sizeof(diff_with_b));
        for(char ch: s) {
            ch -= 'a';
            for(int i = 0; i < 26; i++) {
                if(i == ch) continue;
                diff[ch][i]++;
                diff_with_b[ch][i]++;
                diff_with_b[i][ch] = --diff[i][ch];
                diff[i][ch] = max(diff[i][ch], 0);
                ans = max(ans, max(diff_with_b[ch][i], diff_with_b[i][ch]));
            }
        }
        return ans;
    }
};