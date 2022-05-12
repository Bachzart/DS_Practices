/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

/* method 1 */
class NumMatrix {
public:
    vector<vector<int>> prefixsum = vector<vector<int>>(205, vector<int>(205));
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prefixsum[i][j + 1] = prefixsum[i][j] + matrix[i][j];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        while(row1 <= row2) {
            sum += prefixsum[row1][col2 + 1] - prefixsum[row1][col1];
            row1++;
        }
        return sum;
    }
};

/* method 2 */
class NumMatrix {
public:
    vector<vector<int>> prefixsum = vector<vector<int>>(205, vector<int>(205));
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m > 0) {
            int n = matrix[0].size();
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    prefixsum[i + 1][j + 1] = prefixsum[i][j + 1] + prefixsum[i + 1][j] - prefixsum[i][j] + matrix[i][j];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixsum[row2 + 1][col2 + 1] - prefixsum[row1][col2 + 1] - prefixsum[row2 + 1][col1] + prefixsum[row1][col1];
    }
};