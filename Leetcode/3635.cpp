/*
use greedy, same as 3633
*/
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto deal = [](vector<int>& v1, vector<int>& v2, vector<int>& v3, vector<int>& v4) -> int {
            int n = v1.size(), m = v3.size();
            int first_finsh = INT_MAX;
            for(int i = 0; i < n; ++i) {
                first_finsh = min(first_finsh, v1[i] + v2[i]);
            }

            int ans = INT_MAX;
            for(int i = 0; i < m; ++i) {
                ans = min(ans, max(v3[i], first_finsh) + v4[i]);
            }
            return ans;
        };

        return min(deal(landStartTime, landDuration, waterStartTime, waterDuration), 
                        deal(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
