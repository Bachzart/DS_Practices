class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        int tr = 0, tc = 0;
        vector<vector<int>> ret(r, vector<int>(c));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ret[i][j] = mat[tr][tc++];
                if(tc == n) {
                    tr++;
                    tc = 0;
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if(m * n != r * c) return mat;
        vector<vector<int>> ret(r, vector<int>(c));
        for(int index = 0; index < m * n; index++) {
            ret[index / c][index % c] = mat[index / n][index % n];
        }
        return ret;
    }
};