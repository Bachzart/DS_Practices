/* violent solution */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        vector<int> cnt(26);
        for(int i = 0; i < plen; i++) {
            cnt[p[i] - 'a']++;
        }
        vector<int> ret;
        for(int i = 0; i < slen - plen; i++) {
            vector<int> tmp(26);
            for(int j = i; j < i + plen; j++) {
                tmp[s[j] - 'a']++;
            }
            if(tmp == cnt) ret.push_back(i);
        }
        return ret;
    }
};

/* sliding window */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(slen < plen) return {};
        vector<int> ret, cnt(26), tmp(26);
        for(int i = 0; i < plen; i++) {
            cnt[p[i] - 'a']++;
            tmp[s[i] - 'a']++;
        }
        if(cnt == tmp) ret.push_back(0);
        for(int i = 0; i < slen - plen; i++) {
            tmp[s[i]- 'a']--;
            tmp[s[i + plen] - 'a']++;
            if(tmp == cnt) ret.push_back(i + 1);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(slen < plen) return {};
        vector<int> ret, cnt(26);
        for(int i = 0; i < plen; i++) {
            cnt[s[i] - 'a']++;
            cnt[p[i] - 'a']--;
        }
        int diff = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0) diff++;
        }
        if(diff == 0) ret.push_back(0);
        for(int i = 0; i < slen - plen; i++) {
            // left 
            if(cnt[s[i] - 'a'] == 1) diff--;
            else if(cnt[s[i] - 'a'] == 0) diff++;
            cnt[s[i] - 'a']--;
            // right
            if(cnt[s[i + plen] - 'a'] == -1) diff--;
            else if(cnt[s[i + plen] - 'a'] == 0) diff++;
            cnt[s[i + plen] - 'a']++;
            // judge
            if(diff == 0) ret.push_back(i + 1);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int slen = s.length(), plen = p.length();
        if(slen < plen) return {};
        vector<int> ret, cnt(26);
        for(int i = 0; i < plen; i++) {
            cnt[p[i] - 'a']++;
        }
        int left = 0, right = 0;
        while(right < slen) {
            cnt[s[right] - 'a']--;
            while(cnt[s[right] - 'a'] < 0) {
                cnt[s[left] - 'a']++;
                left++;
            }
            if(right - left + 1 == plen) ret.push_back(left);
            right++;
        }
        return ret;
    }
};