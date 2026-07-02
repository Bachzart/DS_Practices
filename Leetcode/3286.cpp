/*
Method 2: 0-1 BFS
*/
class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector dis(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        dis[0][0] = grid[0][0];

        while(!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();
            if(cx == m - 1 && cy == n - 1) return true;

            for(auto& [dx, dy]: DIRS) {
                int nx = cx + dx, ny = cy + dy;
                
                if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                
                int cost = dis[cx][cy] + grid[nx][ny];

                if(cost >= health) continue;
                if(cost < dis[nx][ny]) {
                    dis[nx][ny] = cost;
                    if(grid[nx][ny] == 0) {
                        q.emplace_front(nx, ny);
                    } else {
                        q.emplace_back(nx, ny);
                    }
                }
            }
        }

        return false;
    }
};

/*
Method 1: Dijkstra

class Solution {
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector dis(m, vector<int>(n, -1));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        while(!pq.empty()) {
            auto [val, cx, cy] = pq.top();
            pq.pop();
            if(dis[cx][cy] >= 0) continue;
            dis[cx][cy] = val;
            for(int k = 0; k < 4; ++k) {
                int nx = cx + dirs[k][0];
                int ny = cy + dirs[k][1];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || dis[nx][ny] >= 0) continue;
                pq.emplace(val + grid[nx][ny], nx, ny);
            }
        }

        return dis[m - 1][n - 1] < health;
    }
};

*/