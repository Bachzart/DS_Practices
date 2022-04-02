/* dfs */
class Solution {
public:
    vector<int> tmp;
    void dfs(int cur, int n, int k, vector<vector<int>>& ret) {
        if(tmp.size() == k) {
            ret.push_back(tmp);
            return;
        }
        if(cur == n + 1) return;
        tmp.push_back(cur);
        dfs(cur + 1, n, k, ret);
        tmp.pop_back();
        dfs(cur + 1, n, k, ret);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        dfs(1, n, k, ret);
        return ret;
    }
};

/* dfs: tmp.size + (n - cur + 1) < k */
class Solution {
public:
    vector<int> tmp;
    void dfs(int cur, int n, int k, vector<vector<int>>& ret) {
        if(tmp.size() + (n - cur + 1) < k) return;
        if(tmp.size() == k) {
            ret.push_back(tmp);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, n, k, ret);
        tmp.pop_back();
        dfs(cur + 1, n, k, ret);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        dfs(1, n, k, ret);
        return ret;
    }
};

/* iteration */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        int i = 0;
        vector<int> tmp(k, 0);
        while(i >= 0) {
            tmp[i]++;
            if(tmp[i] > n) i--;
            else if(i == k - 1) ret.push_back(tmp);
            else {
                i++;
                tmp[i] = tmp[i - 1];
            }
        }
        return ret;
    }
};