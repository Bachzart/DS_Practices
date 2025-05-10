/*
method 1: dijkstra
*/
class Solution {
    struct State {
        int x, y, dis;
        State(int x, int y, int dis): x(x), y(y), dis(dis) {};
        bool operator < (const State & rth) const {
            return dis > rth.dis;
        }
    };
    const int inf = 0x3fffffff;
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dis(n, vector<int>(m, inf));
        dis[0][0] = 0;

        priority_queue<State> q;
        q.push(State(0, 0, 0));
        while(!q.empty()) {
            State s = q.top(); q.pop();
            if(vis[s.x][s.y])
                continue;
            if(s.x == n - 1 && s.y == m - 1)
                break;
            
            vis[s.x][s.y] = true;
            for(int i = 0; i < 4; ++i) {
                int newx = s.x + dirs[i][0];
                int newy = s.y + dirs[i][1];
                if(0 > newx || newx >= n || 0 > newy || newy >= m)
                    continue;
                int dist = max(dis[s.x][s.y], moveTime[newx][newy]) + (s.x + s.y) % 2 + 1;
                if(dis[newx][newy] > dist) {
                    dis[newx][newy] = dist;
                    q.push(State(newx, newy, dist));
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};

/*
method 2: bfs, TLE

class Solution {
private:
    struct State {
        int x;
        int y;
        int dis;
        State(int x, int y, int dis) : x(x), y(y), dis(dis) {};
    };
public:
    const int inf = 0x3f3f3f3f;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, inf));
        dis[0][0] = 0;

        queue<State> q;
        q.push(State(0, 0, 0));
        int cnt = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                State s = q.front();
                q.pop();
                
                if(vis[s.x][s.y])
                    continue;
                    
                vis[s.x][s.y] = 1;
                for(int i = 0; i < 4; ++i) {
                    int newx = s.x + dirs[i][0];
                    int newy = s.y + dirs[i][1];

                    if(0 > newx || newx >= n || 0 > newy || newy >= m)
                        continue;
                    int dist = max(dis[s.x][s.y], moveTime[newx][newy]) + ((cnt & 1) == 0 ? 1 : 2);
                    if(dis[newx][newy] > dist) {
                        dis[newx][newy] = dist;
                        vis[newx][newy] = 0;
                        q.push(State(newx, newy, dist));
                    }
                }
                
            }
            ++cnt;
        }
        return dis[n - 1][m - 1];
    }
};
*/