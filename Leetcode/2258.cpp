class Solution {
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    bool check(vector<vector<int>>& grid, int t) {
        int m = grid.size(), n = grid[0].size();
        bool fire[m][n]; memset(fire, 0, sizeof(fire));
        vector<pair<int, int>> f, q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    fire[i][j] = true;
                    f.emplace_back(i, j);
                }
            }
        }
        auto separate_fire = [&] () {
            vector<pair<int, int>> nf;
            for(auto &[i, j]: f) {
                for(auto [dx, dy]: dirs) {
                    int x = i + dx, y = j + dy;
                    if(0 <= x && x < m && 0 <= y && y < n && !fire[x][y] && grid[x][y] != 2) {
                        fire[x][y] = true;
                        nf.emplace_back(x, y);
                    }
                }
            }
            f = move(nf);
        };
        while(t-- && !f.empty()) separate_fire();
        if(fire[0][0]) return false;
        bool vis[m][n]; memset(vis, 0, sizeof(vis));
        vis[0][0] = true;
        q.emplace_back(0, 0);
        while(!q.empty()) {
            vector<pair<int, int>> nq;
            for(auto &[i, j]: q) {
                if(!fire[i][j]) {
                    for(auto [dx, dy]: dirs) {
                        int x = i + dx, y = j + dy;
                        if(0 <= x && x < m && 0 <= y && y < n && !fire[x][y] && !vis[x][y] && grid[x][y] != 2) {
                            if(x == m - 1 && y == n - 1) return true;
                            vis[x][y] = true;
                            nq.emplace_back(x, y);
                        }
                    }
                }
            }
            q = move(nq);
            separate_fire();
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int left = -1, right = m * n;
        while(left < right) {
            int mid = (left + right + 1) / 2;
            if(check(grid, mid)) left = mid;
            else right = mid - 1;
        }
        return left < m * n ? left : 1e9;
    }
};