class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size(), i;
        int times[100000] = {0};
        for(i = 0; i < n; i++) {
            times[nums[i]]++;
        }
        for(i = 0; i < n; i++) {
            if(times[i] > 1) break;
        }
        return i;
    }
};