class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        vector dis(n, vector<int>(n, -1));
        vector<pair<int, int>> q;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j]) {
                    dis[i][j] = 0;
                    q.emplace_back(i, j);
                }
            }
        }

        // Multi-Source BFS
        vector<vector<pair<int, int>>> groups = {q};
        while(!q.empty()) {
            auto tmp = move(q);
            for(auto& [i, j]: tmp) {
                for(auto& [dx, dy]: dirs) {
                    int x = i + dx, y = j + dy;
                    if(0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
                        dis[x][y] = groups.size();
                        q.emplace_back(x, y);
                    }
                }
            }
            groups.push_back(q);
        }

        // Disjoint Set
        vector<int> fa(n * n);
        ranges::iota(fa, 0);
        auto find = [&](this auto&& find, int x) -> int {
            return fa[x] == x ? x : fa[x] = find(fa[x]);
        };

        for(int ans = static_cast<int>(groups.size()) - 2; ans > 0; --ans) {
            for(auto& [i, j]: groups[ans]) {
                for(auto& [dx, dy]: dirs) {
                    int x = i + dx, y = j + dy;
                    if(0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= ans) {
                        fa[find(x * n + y)] = find(i * n + j);
                    }
                }
            }
            if(find(0) == find(n * n - 1)) {
                return ans;
            }
        }
        return 0;
    }
};