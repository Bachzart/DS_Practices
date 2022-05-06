class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        int n = mat.size();
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(mat[i][j], mat[n - 1 - i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        if(mat == target) return true;
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(mat[i][j], mat[n - 1 - i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        if(mat == target) return true;
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                swap(mat[i][j], mat[n - 1 - i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        if(mat == target) return true;
        return false;
    }
};

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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        for(int i = 0; i < 3; i++) {
            rotate(mat);
            if(mat == target) return true;
        }
        return false;
    }
};