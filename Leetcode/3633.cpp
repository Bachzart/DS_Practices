/*
method 3: greedy
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


/*
method 2: violent solutions

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int land_end = landStartTime[i] + landDuration[i];
                int land_water = max(land_end, waterStartTime[j]) + waterDuration[j];
                ans = min(ans, land_water);

                int water_end = waterStartTime[j] + waterDuration[j];
                int water_land = max(water_end, landStartTime[i]) + landDuration[i];
                ans = min(ans, water_land);
            }
        }
        return ans;
    }
};

*/

/*
method 1: violent solution

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int land_end = landStartTime[i] + landDuration[i];
            for(int j = 0; j < m; ++j) {
                int water_end = land_end;
                if(waterStartTime[j] >= land_end) {
                    water_end = waterStartTime[j] + waterDuration[j];
                } else {
                    water_end += waterDuration[j];
                }
                ans = min(water_end, ans);
            }
        }

        for(int i = 0; i < m; ++i) {
            int water_end = waterStartTime[i] + waterDuration[i];
            for(int j = 0; j < n; ++j) {
                int land_end = water_end;
                if(landStartTime[j] >= water_end) {
                    land_end = landStartTime[j] + landDuration[j];
                } else {
                    land_end += landDuration[j];
                }
                ans = min(ans, land_end);
            }
        }
        return ans;
    }
};

*/