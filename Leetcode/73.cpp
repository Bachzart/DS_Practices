/* method 1 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeropoints;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) zeropoints.push_back(make_pair(i, j));
            }
        }
        for(auto it: zeropoints) {
            int x = it.first, y = it.second;
            for(int i = 0; i < n; i++) {
                matrix[x][i] = 0;
            }
            for(int i = 0; i < m; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};

/* method 2 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeropoints;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) zeropoints.push_back(make_pair(i, j));
            }
        }
        int rows[201] = {0}, columns[201] = {0};
        for(auto it: zeropoints) {
            int x = it.first, y = it.second;
            if(!rows[x]) {
                rows[x] = 1;
                for(int i = 0; i < m; i++) {
                    if(i != y) matrix[x][i] = 0;
                }
            }
            if(!columns[y]) {
                columns[y] = 1;
                for(int i = 0; i < n; i++) {
                    if(i != x) matrix[i][y] = 0;
                }
            }
        }
    }
};

/* method 3 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool frow0 = false, fcol0 = false;
        for(int i = 0; i < n; i++) {
            if(!matrix[0][i]) frow0 = true;
        }
        for(int i = 0; i < m; i++) {
            if(!matrix[i][0]) fcol0 = true;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if(frow0) {
            for(int i = 0; i < n; i++) matrix[0][i] = 0;
        }
        if(fcol0) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool fcol0 = false;
        for(int i = 0; i < m; i++) {
            if(!matrix[i][0]) fcol0 = true;
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if(!matrix[0][0]) {
            for(int i = 1; i < n; i++) matrix[0][i] = 0;
        }
        if(fcol0) {
            for(int i = 0; i < m; i++) matrix[i][0] = 0;
        }
    }
};