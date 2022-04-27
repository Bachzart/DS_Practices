class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sxy = 0, sxz = 0, syz = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            int cmax = grid[0][i], rmax = grid[i][0];
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) sxy++;
                if(grid[j][i] > cmax) cmax = grid[j][i];
                if(grid[i][j] > rmax) rmax = grid[i][j];
            }
            syz += cmax;
            sxz += rmax;
        }
        return sxy + sxz + syz;
    }
};