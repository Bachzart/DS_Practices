class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt(26);
        int len = s.length();
        for(int i = 0; i < len; i++) {
            cnt[s[i] - 'a']++;
        }
        int ret = 0;
        bool flag = true;
        while(true) {
            len = target.length();
            for(int i = 0; i < len; i++) {
                cnt[target[i] - 'a']--;
                if(cnt[target[i] - 'a'] < 0) {
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
            ret++;
        }
        return ret;
    }
};

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> cnt1(26), cnt2(26);
        int len = s.length();
        for(char c: s) {
            cnt1[c - 'a']++;
        }
        for(char c: target) {
            cnt2[c - 'a']++;
        }
        int min_val = INT_MAX;
        for(char c: target) {
            min_val = min(min_val, cnt1[c - 'a'] / cnt2[c - 'a']);
        }
        return min_val;
    }
};