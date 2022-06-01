/* sort + greedy */
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cities(n);
        for(auto &v: roads) {
            cities[v[0]]++;
            cities[v[1]]++;
        }
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return cities[i] > cities[j]; });
        int val = n;
        for(int i = 0; i < n; i++) {
            cities[indices[i]] = val--;
        }
        long long ret = 0;
        for(auto &v: roads) {
            ret += (cities[v[0]] + cities[v[1]]);
        }
        return ret;
    }
};

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n + 1);
        for(auto &v: roads) {
            degree[v[0]]++;
            degree[v[1]]++;
        }
        sort(degree.begin(), degree.end());
        long long ret = 0;
        for(int i = 0; i <= n; i++) {
            ret += i * (long long)degree[i];
        }
        return ret;
    }
};