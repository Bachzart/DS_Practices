/* method 1 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        int letters[26] = {0}, i = 0;
        while(i < s.length()) letters[s[i++] - 'a']++;
        i = 0;
        while(i < t.length()) {
            int tmp = --letters[t[i++] - 'a'];
            if(tmp < 0) break;
        }
        return t[--i];
    }
};

/* method 2 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for(char ch: s) sum1 += ch;
        for(char ch: t) sum2 += ch;
        return sum2 - sum1;
    }
};

/* method 3 */
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret = 0;
        for(char ch: s) ret ^= ch;
        for(char ch: t) ret ^= ch;
        return ret;
    }
};