/* sliding window + prefix sum */
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0, sum = 0;
        int n = nums.size();
        int left = 0, right = 0;
        while(right < n) {
            sum += nums[right];
            long long product = sum * (right - left + 1);
            while(left <= right && product >= k) {
                sum -= nums[left];
                left++;
                product = sum * (right - left + 1);
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};