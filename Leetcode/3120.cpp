/*
method 2: hash with int
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int mask[2]{};
        for(char c: word) {
            mask[c >> 5 & 1] |= 1 << (c & 31);
        }
        return popcount(1u * mask[0] & mask[1]);
    }
};

/*
method 1: hash with array

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0};
        int upper[26] = {0};
        for(char c: word) {
            if('a' <= c && c <= 'z') {
                ++lower[c - 'a'];
            } else if('A' <= c && c <= 'Z') {
                ++upper[c - 'A'];
            }
        }
        int cnt = 0;
        for(int i = 0; i < 26; ++i) {
            if(lower[i] && upper[i])
                ++cnt;
        }
        return cnt;
    }
};

*/