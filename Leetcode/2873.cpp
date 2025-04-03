/*
method 1: Greedy
*/
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, imax = 0, dmax = 0;
        for(int k = 0; k < n; ++k) {
            res = max(res, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }
        return res;
    }
};

/*
method 2: Greedy + prefix sum

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n), rightMax(n);
        for(int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
            rightMax[n - i - 1] = max(rightMax[n - i], nums[n - i]);
        }
        long long res = 0;
        for(int j = 1; j < n - 1; ++j)
            res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
        return res;
    }
};
*/

/*
method 3: Greedy

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int k = 2; k < n; ++k) {
            int m = nums[0];
            for(int j = 1; j < k; ++j) {
                res = max(res, (long long)(m - nums[j]) * nums[k]);
                m = max(m, nums[j]);
            }
        }
        return res;
    }
};
*/

/*
method 4: violent solutions

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = LONG_MIN;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    long long t = 1LL * nums[k] * (nums[i] - nums[j]);
                    ans = max(ans, t);
                }
            }
        }
        return ans > 0 ? ans : 0;
    }
};
*/