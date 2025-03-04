class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int preMin = arrays[0][0], preMax = arrays[0][arrays[0].size() - 1];
        int ans = INT_MIN, n;
        for(int i = 1; i < arrays.size(); ++i) {
            n = arrays[i].size();
            ans = max(ans, abs(preMin - arrays[i][n - 1]));
            ans = max(ans, abs(preMax - arrays[i][0]));
            preMin = min(preMin, arrays[i][0]);
            preMax = max(preMax, arrays[i][n - 1]);
        }
        return ans;
    }
};