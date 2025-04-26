class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int last_min = -1, last_max = -1, border = -1;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            if(minK > nums[i] || maxK < nums[i]) {
                last_min = -1;
                last_max = -1;
                border = i;
            }
            if(nums[i] == minK) 
                last_min = i;
            if(nums[i] == maxK)
                last_max = i;
            if(last_min != -1 && last_max != -1)
                ans += min(last_min, last_max) - border;
        }
        return ans;
    }
};