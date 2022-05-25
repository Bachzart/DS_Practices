/* dp */
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0] == ')') return false;
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> f;
        for(int i = 0; i < n; i++) {
            f.push_back(vector<vector<bool>>());
            for(int j = 0; j < m; j++) {
                f.back().push_back(vector<bool>(n + m));
            }
        }
        f[0][0][1] = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int t = grid[i][j] == '(' ? 1 : -1;
                for(int k = 0; k < n + m; k++) {
                    int kk = k - t;
                    if(kk < 0 || kk >= n + m) continue;
                    if(i > 0) f[i][j][k] = f[i][j][k] || f[i - 1][j][kk];
                    if(j > 0) f[i][j][k] = f[i][j][k] || f[i][j - 1][kk];
                }
            }
        }
        return f[n - 1][m - 1][0];
    }
};