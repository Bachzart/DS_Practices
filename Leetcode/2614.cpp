class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int maxPrime = 0;
        auto f = [&](int k) -> bool {
            if(k <= 1) 
                return false;
            for(int i = 2; i * i <= k; ++i)
                if(k % i == 0)
                    return false;
            return true;
        };
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(f(nums[i][i]))
                maxPrime = max(maxPrime, nums[i][i]);
            if(f(nums[i][n - i - 1]))
                maxPrime = max(maxPrime, nums[i][n - i - 1]);
        }
        return maxPrime;
    }
};