class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret;
        int i = 0, j = 0;
        while(i < word1.length() && j < word2.length()) {
            ret += i <= j ? word1[i++] : word2[j++];
        }
        while(i < word1.length()) ret += word1[i++];
        while(j < word2.length()) ret += word2[j++];
        return ret;
    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret;
        int i = 0, j = 0;
        while(i < word1.length() || j < word2.length()) {
            if(i < word1.length()) ret += word1[i++];
            if(j < word2.length()) ret += word2[j++];
        }
        return ret;
    }
};