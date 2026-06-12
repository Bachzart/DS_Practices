class LcaBinaryLifting {
    vector<int> depth;
    vector<vector<int>> pa;
public:
    LcaBinaryLifting(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int m = bit_width((unsigned) n);
        vector<vector<int>> g(n);
        for(auto& e: edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        depth.resize(n);
        pa.resize(n, vector<int>(m, -1));
        auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
            pa[x][0] = fa;
            for(int y: g[x]) {
                if(y != fa) {
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);

        for(int i = 0; i < m - 1; ++i) {
            for(int x = 0; x < n; ++x) {
                if(int p = pa[x][i]; p != -1) {
                    pa[x][i + 1] = pa[p][i];
                }
            }
        }
    }

    int get_kth_ancestor(int node, int k) {
        for(; k; k &= k - 1) {
            node = pa[node][countr_zero((unsigned)k)];
        }
        return node;
    }
    int get_lca(int x, int y) {
        if(depth[x] > depth[y]) {
            swap(x, y);
        }
        y = get_kth_ancestor(y, depth[y] - depth[x]);
        if(y == x) {
            return x;
        }
        for(int i = pa[x].size() - 1; i >= 0; --i) {
            int px = pa[x][i], py = pa[y][i];
            if(px != py) {
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }
    int get_dis(int x, int y) {
        return depth[x] + depth[y] - depth[get_lca(x, y)] * 2;
    }
};

constexpr int MOD = 1'000'000'007;
constexpr int MX = 100'000;

constexpr std::array<int, MX> pow2 = [] {
    std::array<int, MX> a{};
    a[0] = 1;
    for(int i = 1; i < MX; ++i) {
        a[i] = 1LL * a[i - 1] * 2 % MOD;
    }
    return a;
}();

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LcaBinaryLifting g(edges);
        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0] - 1;
            int y = queries[i][1] - 1;
            if(x != y) {
                ans[i] = pow2[g.get_dis(x, y) - 1];
            }
        }
        return ans;
    }
};