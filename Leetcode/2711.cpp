/*
method 1: prefix sum
*/
class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            int x = i, y = 0;
            set<int> s;
            while(x < m && y < n) {
                ret[x][y] += s.size();
                s.insert(grid[x][y]);
                ++x, ++y;
            }
        }
        for(int j = 1; j < n; ++j) {
            int x = 0, y = j;
            set<int> s;
            while(x < m && y < n) {
                ret[x][y] += s.size();
                s.insert(grid[x][y]);
                ++x, ++y;
            }
        }
        for(int i = 0; i < m; ++i) {
            int x = i, y = n - 1;
            set<int> s;
            while(x >= 0 && y >= 0) {
                ret[x][y] -= s.size();
                ret[x][y] = abs(ret[x][y]);
                s.insert(grid[x][y]);
                --x, --y;
            }
        }
        for(int j = n - 2; j >= 0; --j) {
            int x = m - 1, y = j;
            set<int> s;
            while(x >= 0 && y >= 0) {
                ret[x][y] -= s.size();
                ret[x][y] = abs(ret[x][y]);
                s.insert(grid[x][y]);
                --x, --y;
            }
        }
        return ret;
    }
};

/*
method 2: simulation

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> ret;
        int n = grid.size();
        int m = grid[0].size();
        auto count = [&](int r, int c) -> int {
            unordered_set<int> st1;
            unordered_set<int> st2;
            for(int i = r + 1, j = c + 1; i < n && j < m; ++i, ++j) 
                st1.insert(grid[i][j]);
            for(int i = r - 1, j = c - 1; i >= 0 && j >= 0; --i, --j) 
                st2.insert(grid[i][j]);
            return abs((int)st1.size() - (int)st2.size());
        };
        for(int i = 0; i < n; ++i) {
            int m = grid[i].size();
            vector<int> t;
            for(int j = 0; j < m; ++j) {
                t.push_back(count(i, j));
            }
            ret.push_back(t);
        }
        return ret;
    }
};
*/