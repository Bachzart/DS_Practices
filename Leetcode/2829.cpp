/*
method 1: math
*/
class Solution {
public:
    int minimumSum(int n, int k) {
        int m = min(n, k / 2);
        return (m * (m + 1) +  (n - m) * (k + k + n - m - 1)) / 2;
    }
};


/*
method 2: greddy

class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        unordered_map<int, int> ht;
        int cnt = 0;
        for(int i = 1; cnt < n; ++i) {
            if(ht[k - i] == 0) {
                ans += i;
                ++cnt;
                ++ht[i];
            }
        }
        return ans;
    }
};
*/

/*
method 2: backtracking
class Solution {
public:
    int minimumSum(int n, int k) {
        int ans = 0;
        unordered_map<int, int> ht;
        vector<int> t;
        function<void(int)> dfs = [&](int i) {
            if(t.size() == n) {
                ans = min(ans, accumulate(t.begin(), t.end(), 0));
                return;
            }
            if(ht[k - i] == 0) {
                ++ht[i];
                t.push_back(i);
                dfs(i + 1);
                --ht[i];
            }
            dfs(i + 1);
        };
        dfs(1);
        return ans;
    }
};
*/