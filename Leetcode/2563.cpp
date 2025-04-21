/*
method 2: three pointers
*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = n, right = n;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            while(right > 0 && nums[right - 1] > upper - nums[i])
                --right;
            while(left > 0 && nums[left - 1] >= lower - nums[i]) 
                --left;
            ans += min(right, i) - min(left, i);
        }
        return ans;
    }
};

/*
method 1: binary search 

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long cnt = 0;
        for(int i = 0; i < n; ++i) {
            auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            cnt += r - l;
        }
        return cnt;
    }
};

*/