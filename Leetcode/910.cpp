class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mymin, mymax, size = nums.size();
        int ans = nums[size - 1] - nums[0];
        for(int i = 0; i < size - 1; i++) {
            mymin = min(nums[0] + k, nums[i + 1] - k);
            mymax = max(nums[size - 1] - k, nums[i] + k);
            ans = min(ans, mymax - mymin);
        }
        return ans;
    }
};