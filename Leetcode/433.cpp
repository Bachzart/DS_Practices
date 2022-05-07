/* method 1: bfs */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> ht;
        unordered_set<string> visited;
        char keys[4] = {'A', 'C', 'G', 'T'};
        for(auto &s: bank) {
            ht.insert(s);
        }
        if(start == end) return 0;
        if(!ht.count(end)) return -1;
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int step = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string tmp = q.front(); q.pop();
                for(int j = 0; j < 8; j++) {
                    for(int k = 0; k < 4; k++) {
                        if(keys[k] != tmp[j]) {
                            string next = tmp;
                            next[j] = keys[k];
                            if(!visited.count(next) && ht.count(next)) {
                                if(next == end) return step;
                                q.push(next);
                                visited.insert(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

/* method 2: bfs + preprocess */
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int len1 = start.length();
        int size = bank.size();
        vector<vector<int>> adj(size);
        int endindex = -1;
        for(int i = 0; i < size; i++) {
            if(end == bank[i]) {
                endindex = i;
            }
            for(int j = i + 1; j < size; j++) {
                int mutations = 0;
                for(int k = 0; k < len1; k++) {
                    if(bank[i][k] != bank[j][k]) mutations++;
                    if(mutations > 1) break;
                }
                if(mutations == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        if(endindex == -1) return -1;
        queue<int> q;
        vector<bool> visited(size, false);
        int step = 1;
        for(int i = 0; i < size; i++) {
            int mutations = 0;
            for(int k = 0; k < len1; k++ ){
                if(start[k] != bank[i][k]) mutations++;
                if(mutations > 1) break;
            }
            if(mutations == 1) {
                q.push(i);
                visited[i] = true;
            }
        }
        while(!q.empty()) {
            int amount = q.size();
            for(int i = 0; i < amount; i++) {
                int cur = q.front(); q.pop();
                if(cur == endindex) return step;
                for(auto &next: adj[cur]) {
                    if(visited[next]) continue;
                    visited[next] = true;
                    q.push(next);
                }
            }
            step++;
        }
        return -1;
    }
};