class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        for(int i = 0; i < m + n - 1; i++) {
            if(i % 2 == 0) {
                int x = i < m ? i : m - 1;
                int y = i < m ? 0 : i - m + 1;
                while(x >= 0 && y < n) {
                    ans.push_back(mat[x][y]);
                    x--, y++;
                }
            } else {
                int x = i < n ? 0 : i - n + 1;
                int y = i < n ? i : n - 1;
                while(x < m && y >= 0) {
                    ans.push_back(mat[x][y]);
                    x++, y--;
                }
            }
        }
        return ans;
    }
};

