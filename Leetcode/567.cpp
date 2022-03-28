/* method 1: sliding window */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        vector<int> cnt1(26), cnt2(26);
        for(int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a']++;
            cnt2[s2[i] - 'a']++;
        }
        if(cnt1 == cnt2) return true;
        for(int i = n; i < m; i++) {
            ++cnt2[s2[i] - 'a'];
            --cnt2[s2[i - n] - 'a'];
            if(cnt1 == cnt2) return true;
        }
        return false;
    }
};

/* method 2: just use one vector */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++) {
            --cnt[s1[i] - 'a'];
            ++cnt[s2[i] - 'a'];
        }
        int diff = 0;
        for(int c: cnt) {
            if(c != 0) diff++;
        }
        if(diff == 0) return true;
        for(int i = n; i < m; i++) {
            int x = s2[i] - 'a', y = s2[i - n] - 'a';
            if(x == y) continue;
            if(cnt[x] == 0) diff++;
            cnt[x]++;
            if(cnt[x] == 0) diff--;
            if(cnt[y] == 0) diff++;
            cnt[y]--;
            if(cnt[y] == 0) diff--;
            if(diff == 0) return true;
        }
        return false;
    }
};

/* method 3: use tow pointers */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if(n > m) return false;
        vector<int> cnt(26);
        for(int i = 0; i < n; i++) {
            cnt[s1[i] - 'a']--;
        }
        int left = 0;
        for(int right = 0; right < m; right++) {
            int x = s2[right] - 'a';
            cnt[x]++;
            while(cnt[x] > 0) {
                cnt[s2[left] - 'a']--;
                left++;
            }
            if(right - left + 1 == n) return true;
        }
        return false;
    }
};