class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int dist[10][10];
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        memset(dist, -1, sizeof(dist));
        vector<vector<int>> inq(m, vector<int>(n));
        queue<pair<int, int>> q;
        int cnt = 0, ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.emplace(i, j);
                    dist[i][j] = 0;
                    inq[i][j] = 1;
                } else if(grid[i][j] == 1) cnt++;
            }
        }
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++) {
                int newx = x + dirs[d][0], newy = y + dirs[d][1];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && !inq[newx][newy] && grid[newx][newy]) {
                    dist[newx][newy] = dist[x][y] + 1;
                    q.emplace(newx, newy);
                    inq[newx][newy] = 1;
                    if(grid[newx][newy] == 1) {
                        cnt--;
                        ans = dist[newx][newy];
                        if(cnt == 0) break;
                    }
                }
            }
        }
        return cnt ? -1 : ans;
    }
};