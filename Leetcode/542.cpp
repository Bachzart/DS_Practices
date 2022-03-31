/* bfs: version 1, these codes will cause time limited exceeded. */
class Solution {
public:
    int X[4] = {1, -1, 0, 0};
    int Y[4] = {0, 0, 1, -1};
    bool isvalid(vector<vector<int>>& mat, int x, int y) {
        if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) return false;
        return true; 
    }
    int bfs(vector<vector<int>>& mat, int sr, int sc) {
        set<pair<int, int>> ht;
        int level = 0;
        if(mat[sr][sc] == 0) return level;
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        ht.insert(make_pair(sr, sc));
        while(!q.empty()) {
            int size = q.size();
            level++;
            for(int i = 0; i < size; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++) {
                    int newx = x + X[j], newy = y + Y[j];
                    if(isvalid(mat, newx, newy) && ht.find(make_pair(newx, newy)) == ht.end()) {
                        if(mat[newx][newy] == 0) return level;
                        q.emplace(newx, newy);
                        ht.insert(make_pair(newx, newy));
                    }
                }
            }
        }
        return -1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> ret(mat.size(), vector<int>(mat[0].size()));
        int m = mat.size(), n = mat[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ret[i][j] = bfs(mat, i, j);
            }
        }
        return ret;
    }
};

/* bfs: version 2 */
class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> inq(m, vector<int>(n));
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.emplace(i, j);
                    inq[i][j] = 1;
                }
            }
        }
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++) {
                int newx = x + dirs[d][0], newy = y + dirs[d][1];
                if(newx >= 0 && newx < m && newy >= 0 && newy < n && !inq[newx][newy]) {
                    dist[newx][newy] = dist[x][y] + 1;
                    q.emplace(newx, newy);
                    inq[newx][newy] = 1;
                }
            }
        }
        return dist;
    }
};