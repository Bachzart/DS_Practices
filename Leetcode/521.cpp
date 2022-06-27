class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;
        int maxlen = max(a.length(), b.length());
        return maxlen;
    }
};