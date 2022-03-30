/* bfs */
class Solution {
public:
    bool inq[55][55] = {false};
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    int bfs(vector<vector<int>>& grid, int sr, int sc, int m, int n) {
        int count = 0;
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            inq[x][y] = true;
            count++;
            for(int i = 0; i < 4; i++) {
                int newX = x + X[i], newY = y + Y[i];
                if(newX < m && newX >= 0 && newY < n && newY >= 0 && grid[newX][newY] && !inq[newX][newY]) {
                    inq[newX][newY] = true;
                    q.emplace(newX, newY);
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(grid[x][y] && !inq[x][y]) {
                    int tmp = bfs(grid, x, y, m, n);
                    ans = tmp > ans ? tmp : ans;
                }
            }
        }
        return ans;
    }
};

/* dfs */
class Solution {
public:
    bool inq[55][55] = {false};
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    bool isvalid(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return false;
        if(inq[x][y] || grid[x][y] == 0) return false;
        return true;
    }
    int dfs(vector<vector<int>>& grid, int x, int y) {
        if(!isvalid(grid, x, y)) return 0;
        inq[x][y] = true;
        int count = 1;
        for(int i = 0; i < 4; i++) {
            int newX = x + X[i], newY = y + Y[i];
            count += dfs(grid, newX, newY);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(grid[x][y] && !inq[x][y]) {
                    int tmp = dfs(grid, x, y);
                    ans = tmp > ans ? tmp : ans;
                }
            }
        }
        return ans;
    }
};