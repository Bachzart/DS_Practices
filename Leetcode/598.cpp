/* volent solution, TLE. */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        vector<vector<int>> mat(m, vector<int>(n));
        int max_value = INT_MIN, cnt = 0;
        for(auto &v: ops) {
            for(int x = 0; x < v[0]; x++) {
                for(int y = 0; y < v[1]; y++) {
                    mat[x][y]++;
                    max_value = max(max_value, mat[x][y]);
                }
            }
        } 
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(max_value == mat[x][y]) cnt++;
            }
        }
        return cnt;
    }
};

/* get the intersection. */
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto &v: ops) {
            m = min(m, v[0]);
            n = min(n, v[1]);
        }
        return n * m;
    }
};