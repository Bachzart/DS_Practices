class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int index = 0, count = m * n, r = 0, c = 0;
        if(count == 1) return matrix[0];
        int U = 0, D = m - 1, L = 0, R = n - 1;
        vector<int> ret(count);
        while(index < count) {
            while(index < count && c < R) ret[index++] = matrix[r][c++];
            while(index < count && r < D) ret[index++] = matrix[r++][c];
            while(index < count && c > L) ret[index++] = matrix[r][c--];
            while(index < count && r > U) ret[index++] = matrix[r--][c];
            r++, c++;
            U++, D--, L++, R--;
            if(index == count - 1) {
                ret[index++] = matrix[r][c];
                break;
            }
        } 
        return ret;
    }
};