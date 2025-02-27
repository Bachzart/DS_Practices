class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int premin = arrays[0][0], premax = arrays[0][arrays[0].size() - 1];
        int res = INT_MIN;
        for(int i = 1; i < n; ++i) {
            int t = arrays[i].size();
            res = max(res, max(abs(premin - arrays[i][t - 1]), 
                                abs(premax - arrays[i][0])));
            premin = min(premin, arrays[i][0]);
            premax = max(premax, arrays[i][t - 1]);
        }
        return res;
    }
};