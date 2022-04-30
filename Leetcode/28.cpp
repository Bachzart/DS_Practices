/* method 1: violent solutions */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = -1, len1 = haystack.length(), len2 = needle.length();
        if(len2 == 0) return 0;
        for(int i = 0; i < len1; i++) {
            if(haystack[i] == needle[0]) {
                int tmp = i + 1, j;
                for(j = 1; j < len2; j++, tmp++) {
                    if(needle[j] != haystack[tmp]) break;
                }
                if(j == len2) {
                    pos = i;
                    break;
                }
            } 
        }
        return pos;
    }
};

/* method 2 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};