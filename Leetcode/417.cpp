/* dfs */
class Solution {
public:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    vector<vector<int>> heights;
    void dfs(int row, int col, vector<vector<bool>>& ocean) {
        int m = ocean.size(), n = ocean[0].size();
        if(ocean[row][col]) return;
        ocean[row][col] = true;
        for(int i = 0; i < 4; i++) {
            int newx = row + X[i], newy = col + Y[i];
            if(newx >= 0 && newx < m && newy >= 0 && newy < n && heights[newx][newy] >= heights[row][col]) {
                dfs(newx, newy, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            dfs(i, 0, pacific);
        }
        for(int i = 1; i < n; i++) {
            dfs(0, i, pacific);
        }
        for(int i = 0; i < m; i++) {
            dfs(i, n - 1, atlantic);
        }
        for(int i = 0; i < n - 1; i++) {
            dfs(m - 1, i, atlantic);
        }
        vector<vector<int>> ret;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) ret.push_back({i, j});
            }
        }
        return ret;
    }
};

/* bfs */
class Solution {
public:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    vector<vector<int>> heights;
    void bfs(int x, int y, vector<vector<bool>>& ocean) {
        if(ocean[x][y]) return;
        int m = ocean.size(), n = ocean[0].size();
        ocean[x][y] = true;
        queue<pair<int, int>> q;
        q.emplace(x, y);
        while(!q.empty()) {
            int xtmp = q.front().first, ytmp = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int newx = xtmp + X[i], newy = ytmp + Y[i];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && heights[newx][newy] >= heights[xtmp][ytmp] && !ocean[newx][newy]) {
                    ocean[newx][newy] = true;
                    q.emplace(newx, newy);
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            bfs(i, 0, pacific);
        }
        for(int i = 1; i < n; i++) {
            bfs(0, i, pacific);
        }
        for(int i = 0; i < m; i++) {
            bfs(i, n - 1, atlantic);
        }
        for(int i = 0; i < n - 1; i++) {
            bfs(m - 1, i, atlantic);
        }
        vector<vector<int>> ret;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) ret.push_back({i, j});
            }
        }
        return ret;
    }
};