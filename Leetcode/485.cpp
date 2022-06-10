class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, i = 0;
        while(i < n) {
            int j = i;
            while(j < n && nums[j] == 1) {
                ++j;
                ans = max(ans, j - i);
            }
            i = j + 1;
        }
        return ans;
    }
};