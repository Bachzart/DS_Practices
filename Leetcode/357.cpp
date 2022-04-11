/* method 1: violent solution */
class Solution {
public:
    bool isrepeat(int n) {
        int isappear[10] = {0};
        while(n) {
            int tmp = n % 10;
            isappear[tmp]++;
            if(isappear[tmp] > 1) return true;
            n /= 10;
        }
        return false;
    }
    int countNumbersWithUniqueDigits(int n) {
        int end = pow(10, n), count = 0;
        for(int i = 0; i < end; i++) {
            if(isrepeat(i)) count++;
        }
        return end - count;
    }
};

/* method 2: math */
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int count = 10, ans = 9;
        for(int i = 0; i < n - 1; i++) {
            ans *= (9 - i);
            count += ans;
        }
        return count;
    }
};

/* method 3: backtracking */
class Solution {
public:
    vector<int> ht;
    int ans;
    void dfs(int k, int n, bool first) {
        if(k == n) {
            ans++;
            return;
        }
        for(int i = 0; i <= 9; i++) {
            if(hash[i] || (first && i == 0)) continue;
            hash[i] = 1;
            dfs(k + 1, n, false);
            hash[i] = 0;
        }
    }
    int countNumbersWithUniqueDigits(int n) {
        ht.resize(10, 0);
        ans = 0;
        for(int i = 0; i <= n; i++) {
            dfs(0, i, true);
        }
        return ans;
    }
};