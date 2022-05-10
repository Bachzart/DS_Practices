/* bfs */
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        if(n == 1) return 0;
        vector<int> totaltime(n);
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            int tmptime = informTime[node];
            for(int i = 0; i < n; i++) {
                if(manager[i] == node) {
                    q.push(i);
                    totaltime[i] = tmptime + totaltime[node];
                }
            }
        }
        int maxtime = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(maxtime < totaltime[i]) maxtime = totaltime[i];
        }
        return maxtime;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        if(n == 1) return 0;
        vector<int> totaltime(n);
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) indices[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(root);
        while(!q.empty()) {
            int node = q.front(); q.pop();
            int tmptime = informTime[node];
            for(int &i: indices[node]) {
                q.push(i);
                totaltime[i] = tmptime + totaltime[node];
            }
        }
        int maxtime = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(maxtime < totaltime[i]) maxtime = totaltime[i];
        }
        return maxtime;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        if(n == 1) return 0;
        vector<int> totaltime(n);
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        queue<int> q;
        q.push(root);
        int maxtime = INT_MIN;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            int tmptime = informTime[node];
            for(int &i: adj[node]) {
                q.push(i);
                totaltime[i] = tmptime + totaltime[node];
                if(totaltime[i] > maxtime) maxtime = totaltime[i];
            }
        }
        return maxtime;
    }
};

/* dfs */
class Solution {
public:
    vector<int> totaltime = vector<int>(1e5);
    int maxtime = INT_MIN;
    void dfs(int u, vector<vector<int>>& adj, vector<int>& informTime, vector<bool>& vis) {
        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(vis[v] == false) {
                totaltime[v] = informTime[u] + totaltime[u];
                if(maxtime < totaltime[v]) maxtime = totaltime[v];
                dfs(v, adj, informTime, vis);
            }
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        if(n == 1) return 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        vector<bool> vis(n);
        dfs(headID, adj, informTime, vis);
        return maxtime;
    }
};

class Solution {
public:
    vector<int> totaltime = vector<int>(1e5);
    int maxtime = INT_MIN;
    void dfs(int u, vector<vector<int>>& adj, vector<int>& informTime) {
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            totaltime[v] = informTime[u] + totaltime[u];
            if(maxtime < totaltime[v]) maxtime = totaltime[v];
            dfs(v, adj, informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int root = headID;
        if(n == 1) return 0;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            if(manager[i] != -1) adj[manager[i]].push_back(i);
        }
        dfs(headID, adj, informTime);
        return maxtime;
    }
};