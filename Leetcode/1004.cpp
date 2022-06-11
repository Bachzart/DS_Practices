/* sliding window */
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += nums[right] != 1;
            while(sum > k) {
                sum -= nums[left++] == 0;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};