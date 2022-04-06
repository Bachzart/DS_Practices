class Solution {
public:
    int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj) {
        int n = adj.size();
        queue<int> q;
        vector<bool> visit(n);
        q.push_back(u);
        visit[u] = true;
        int node = -1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            node = cur;
            for(auto & v: adj[cur]) {
                if(!visit[v]) {
                    visit[v] = true;
                    parent[v] = cur;
                    q.push_back(v);
                }
            }
        }
        return node;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        for(auto & edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> parent(n, -1);
        int x = findLongestNode(0, parent, adj);
        int y = findLongestNode(x, parent, adj);
        vector<int> path;
        parent[x] = -1;
        while(y != -1) {
            path.push_back(y);
            y = parent[y];
        }
        int m = path.size();
        if(m % 2 == 0) return {path[m / 2 - 1], path[m / 2]};
        else return {path[m / 2]};
    }
};