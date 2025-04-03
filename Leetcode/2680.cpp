/*
method 1: bit operation
*/
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        long long mult_bits = 0;
        long long preOrSum = 0;
        for(int i: nums) {
            mult_bits |= preOrSum & i;
            preOrSum |= i;
        }
        long long ans = 0;
        for(int i: nums) {
            ans = max(ans, (preOrSum ^ i) | (1LL * i << k) | mult_bits);
        }
        return ans;
    }
};


/*
method 2: prefix sum

class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> sufOrSum(n);
        sufOrSum[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i) 
            sufOrSum[i] = sufOrSum[i + 1] | nums[i + 1];
        long long ans = 0;
        long preOrSum = 0;
        for(int i = 0; i < n; ++i) {
            long long t;
            t = preOrSum | sufOrSum[i] | (1LL * nums[i] << k);
            ans = max(ans, t);
            preOrSum |= nums[i];
        }
        return ans;
    }
};

*/