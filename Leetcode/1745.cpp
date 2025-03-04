class Solution {
private:
    vector<vector<int>> f;
    int n;
public:
    bool checkPartitioning(string s) {
        n = s.length();
        if(n < 3) return false;
        f.assign(n, vector<int>(n, true));
        for(int i = n - 1; i >= 0; --i)
            for(int j = i + 1; j < n; ++j)
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];

        for(int i = 0; i < n - 2; ++i) {
            if(f[0][i]) {
                for(int j = i + 1; j < n - 1; ++j) {
                    if(f[i + 1][j] && f[j + 1][n - 1])
                        return true;
                }
            }
        }
        return false;
    }
};