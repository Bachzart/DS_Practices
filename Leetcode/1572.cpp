class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            sum += mat[i][i];
            sum += mat[i][j];
        }
        return sum - mat[n / 2][n / 2];
    }
};

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size(), sum = 0;
        for(int i = 0; i < n; i++) {
            sum += mat[i][i] + mat[i][n - i - 1];
        }
        return sum - mat[n / 2][n / 2] * (n & 1);
    }
};