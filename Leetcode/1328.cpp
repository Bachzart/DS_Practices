class Solution {
public:
    string breakPalindrome(string palindrome) {
        string ret;
        int len = palindrome.length();
        if(len == 1) return ret;
        ret = palindrome;
        int i;
        for(i = 0; i < len; ++i) {
            if(ret[i] != 'a') {
                ret[i] = 'a';
                break;
            }
        }
        if(i >= len / 2) {
            ret = palindrome;
            ret[len - 1] = 'b';
        }
        return ret;
    }
};

/*
sbccbs -> abccbs

aca -> bca

bcb -> acb

baab -> aaab

acca -> aaca

acbca -> aabca

*/