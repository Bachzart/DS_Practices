class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int size = words.size(), cnt = 0;
        for(int i = 0; i < size; i++) {
            if(s.find(words[i]) == 0) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(auto &w: words) {
            if(s.substr(0, w.length()) == w) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    bool isprefix(string &w, string &s) {
        if(w.length() > s.length()) return false;
        for(int i = 0; i < w.length(); i++) {
            if(w[i] != s[i]) return false;
        }
        return true;
    }
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(string &w: words) {
            if(isprefix(w, s)) cnt++;
        }
        return cnt;
    }
};