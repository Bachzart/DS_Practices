class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        unordered_map<int, int> ht;
        long long ans = 0;
        int presum = 0;
        ++ht[presum % modulo];
        for(int i = 0; i < n; ++i) {
            presum += nums[i] % modulo == k;
            ans += ht[(presum - k + modulo) % modulo];
            ++ht[presum % modulo];
        }
        return ans;
    }
};