/* violent solution */
class Solution {
public:
    long long appealSum(string s) {
        long long ret = s.length();
        int len = s.length();
        unordered_set<char> ht;
        for(int i = 0; i < len; i++) {
            ht.insert(s[i]);
        }
        ret += ht.size();
        for(int step = 2; step < len; step++) {
            for(int i = 0; i <= len - step; i++) {
                unordered_set<char> ht;
                int start = i, end = i + step;
                while(start < end) {
                    ht.insert(s[start]);
                    start++;
                }
                ret += ht.size();
            }
        }
        return ret;
    }
};

/* violent solution + hash */
class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        int len = s.length();
        unordered_map<string, int> ht;
        for(int i = 0; i < len; i++) {
            string tmp;
            for(int j = i; j < len; j++) {
                tmp.push_back(s[j]);
                ht[tmp]++;
            }
        }
        for(auto &[str, times]: ht) {
            vector<int> cnt(26);
            int l = str.length();
            for(int i = 0; i < l; i++) {
                cnt[str[i] - 'a']++;
            }
            int count = 0;
            for(int i = 0; i < 26; i++) {
                if(cnt[i] > 0) count++;
            }
            ret += count * times;
        }
        return ret;
    }
};

class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        int len = s.length();
        unordered_map<string, int> ht;
        for(int i = 0; i < len; i++) {
            string tmp;
            for(int j = i; j < len; j++) {
                tmp.push_back(s[j]);
                ht[tmp]++;
            }
        }
        for(auto &[str, times]: ht) {
            vector<int> cnt(26);
            int l = str.length();
            int count = 0;
            for(int i = 0; i < l; i++) {
                if(cnt[str[i] - 'a'] == 0) {
                    count++;
                }
                cnt[str[i] - 'a']++;
            }
            ret += count * times;
        }
        return ret;
    }
};

class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        int len = s.length();
        unordered_map<string, int> ht;
        for(int i = 0; i < len; i++) {
            string tmp;
            for(int j = i; j < len; j++) {
                tmp.push_back(s[j]);
                ht[tmp]++;
            }
        }
        for(auto &[str, times]: ht) {
            unordered_set<char> se;
            for(auto &c: str) {
                se.insert(c);
            }
            ret += se.size() * times;
        }
        return ret;
    }
};

/* dp */
class Solution {
public:
    long long appealSum(string s) {
        long long ret = 0;
        int len = s.length();
        vector<int> last(26, -1);
        for(int i = 0, sum_g = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            sum_g += i - last[c];
            ret += sum_g;
            last[c] = i;
        }
        return ret;
    }
};