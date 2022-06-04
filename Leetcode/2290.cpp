/* bfs */
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        dist[0][0] = 0;
        while(!q.empty()) {
            auto u = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int newx = u.first + dirs[i][0];
                int newy = u.second + dirs[i][1];
                if(0 <= newx && newx < m && 0 <= newy && newy < n &&
                 dist[newx][newy] > dist[u.first][u.second] + grid[u.first][u.second]) {
                    dist[newx][newy] = dist[u.first][u.second] + grid[u.first][u.second];
                    q.emplace(newx, newy);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};