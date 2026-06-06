class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), leftSum(n), rightSum(n);
        leftSum[0] = rightSum[n - 1] = 0;
        for(int i = 0; i < n; ++i) {
            if(i != 0) {
                leftSum[i] = leftSum[i - 1] + nums[i - 1];
                rightSum[n - i - 1] = rightSum[n - i] + nums[n - i];
            }
        }
        for(int i = 0; i < n; ++i) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        return ans;
    }
};