class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftmax(n, 0);
        vector<int> rightmin(n, 1e7);
        for(int i = 1; i < n; ++i) {
            leftmax[i] = max(leftmax[i - 1], nums[i - 1]);
        }
        for(int i = n - 2; i >= 0; --i) {
            rightmin[i] = min(rightmin[i + 1], nums[i + 1]);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(leftmax[i] < nums[i] && nums[i] < rightmin[i]) {
                ans += 2;
            } else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                ans += 1;
            }
        }
        return ans;
        return 0;
    }
};