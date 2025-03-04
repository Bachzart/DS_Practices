/*
// method 1: backtracking + dp

class Solution {
private:
    int n;
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
public:
    void dfs(int i, const string &s) {
        if(i == n) {
            ret.push_back(ans);
            return;
        }
        for(int j = i; j < n; ++j) {
            if(f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<int>(n, true));
        for(int i = n - 1; i >= 0; --i)
            for(int j = i + 1; j < n; ++j)
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];

        dfs(0, s);
        return ret;
    }
};
*/

/*
method 2
*/

class Solution {
private:
    int n;
    vector<string> ans;
    vector<vector<string>> ret;
    vector<vector<int>> f;
public:
    void dfs(int i, const string &s) {
        if(i == n) {
            ret.push_back(ans);
            return;
        }
        for(int j = i; j < n; ++j) {
            if(isPalindrome(s, i, j) == 1) {
                ans.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s);
                ans.pop_back();
            }
        }
    }
    int isPalindrome(const string &s, int i, int j) {
        if(f[i][j]) {
            return f[i][j];
        }
        if(i >= j) {
            return f[i][j] = 1;
        }
        return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        f.assign(n, vector<int>(n));

        dfs(0, s);
        return ret;
    }
};