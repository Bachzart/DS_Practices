/*
method 1: violent enumeration, TLE
*/
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long start = pow(10, n - 1), end = pow(10, n);
        unordered_set<string> ht;
        while(start < end) {
            if(start % k == 0) {
                string s = to_string(start);
                bool flag = true;
                for(int left = 0, right = s.length() - 1; left < right; ++left, --right) {
                    if(s[left] != s[right]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    sort(s.begin(), s.end());
                    ht.insert(s);
                }
            }
            ++start;
        }
        long long ans = 0;
        vector<long long> fact(n + 1, 1);
        for(int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i;
        for(const string &s: ht) {
            vector<int> cnt(10);
            for(char c: s) 
                ++cnt[c - '0'];
            long long tot = (n - cnt[0]) * fact[n - 1];
            for(int x: cnt)
                tot /= fact[x];
            ans += tot;
        }
        return ans;
    }
};

/*
method 2: math, AC
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        for(int i = base; i < base * 10; ++i) {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long p = stoll(s);
            if(p % k == 0) {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }
        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        for(const string &s: dict) {
            vector<int> cnt(10);
            for(char c: s) 
                ++cnt[c - '0'];
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for(int x: cnt)
                tot /= factorial[x];
            ans += tot;
        }
        return ans;
    }
};
*/

/*
method 3: violent solutions, TLE

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long start = pow(10, n - 1), end = pow(10, n);
        unordered_set<string> ht;
        while(start < end) {
            if(start % k == 0) {
                string s = to_string(start);
                bool flag = true;
                for(int left = 0, right = s.length() - 1; left < right; ++left, --right) {
                    if(s[left] != s[right]) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    sort(s.begin(), s.end());
                    ht.insert(s);
                }
            }
            ++start;
        }
        long long ans = 0;
        start = pow(10, n - 1), end = pow(10, n);
        while(start < end) {
            string s = to_string(start);
            sort(s.begin(), s.end());
            if(ht.count(s))
                ++ans;
            ++start;
        }
        return ans;
    }
};
*/