class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int minrow = 0, maxOne = 0;
        int m = mat.size();
        for(int i = 0; i < m; ++i) {
            int cntOne = 0, n = mat[i].size();
            cntOne = accumulate(mat[i].begin(), mat[i].end(), 0);
            if(cntOne > maxOne) {
                maxOne = cntOne;
                minrow = i;
            }
        }
        return {minrow, maxOne};
    }
};