class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        for(char &ch: num) {
            cnt[ch - '0']++;
        }
        for(int i = 0; i < num.length(); i++) {
            if(num[i] - '0' != cnt[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool digitCount(string num) {
        vector<int> cnt(10);
        for(char &ch: num) {
            cnt[ch & 15]++;
        }
        for(int i = 0; i < num.length(); i++) {
            if((num[i] & 15) != cnt[i]) return false;
        }
        return true;
    }
};