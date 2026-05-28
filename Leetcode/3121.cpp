/*
method 3: bit operation
*/
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower = 0, upper = 0, invalid = 0;
        for(char c: word) {
            int bit = 1 << (c & 31);
            if(c & 32) {
                lower |= bit;
                if(upper & bit) {
                    invalid |= bit;
                }
            } else {
                upper |= bit;
            }
        }
        return popcount(1u * (lower & upper & ~invalid));
    }
};

/*
method 2: state machine

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> status(27, 0);
        int cnt = 0;
        for(int i = 0; i < word.length(); ++i) {
            int pos = word[i] & 31;
            if(islower(word[i])) {
                if(!status[pos]) {
                    status[pos] = 1;
                } else if(status[pos] == 2) {
                    status[pos] = 3;
                    --cnt;
                }
            } else if(isupper(word[i])) {
                if(!status[pos]) {
                    status[pos] = 3;
                } else if(status[pos] == 1) {
                    status[pos] = 2;
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

*/

/*
method 1: hash

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, -1);
        vector<int> upper(26, -1);
        for(int i = 0; i < word.length(); ++i) {
            if('a' <= word[i] && word[i] <= 'z') {
                lower[word[i] - 'a'] = i;
            } else if('A' <= word[i] && word[i] <= 'Z' && upper[word[i] - 'A'] == -1) {
                upper[word[i] - 'A'] = i;
            }
        }

        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            if(lower[i] != -1 && upper[i] != -1 && lower[i] < upper[i]) {
                ++ans;
            }
        }
        return ans;
    }
};

*/