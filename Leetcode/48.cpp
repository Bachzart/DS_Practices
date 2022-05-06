/* method 1: rotate the image not in-place */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), r = 0, c = 0;
        vector<vector<int>> ret(n, vector<int>(n));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) {
                ret[r++][c] = matrix[i][j];
            }
            r = 0, c++;
        }
        matrix = ret;
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ret(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ret[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = ret;
    }
};


/* method 2: rotate the image in-place */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(), end = n;
        for(int r = 0; r < n / 2; r++) {
            for(int c = r; c < end - 1; c++) {
                swap(matrix[r][c], matrix[c][n - 1 - r]);
                swap(matrix[r][c], matrix[n - 1 - r][n - 1 - c]);
                swap(matrix[r][c], matrix[n - 1 - c][r]);
            }
            end--;
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int r = 0; r < n / 2; r++) {
            for(int c = 0; c < (n + 1) / 2; c++) {
                swap(matrix[r][c], matrix[c][n - 1 - r]);
                swap(matrix[r][c], matrix[n - 1 - r][n - 1 - c]);
                swap(matrix[r][c], matrix[n - 1 - c][r]);
            }
        }
    }
};

/* method 3:  flip the matrix twice */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};