/* method 1: dp */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int maxsum = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            if(maxsum < dp[i]) maxsum = dp[i];
        }
        return maxsum;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0];
        int maxsum = pre;
        for(int i = 1; i < nums.size(); i++) {
            pre = max(nums[i], nums[i] + pre);
            if(maxsum < pre) maxsum = pre;
        }
        return maxsum;
    }
};

/* method 2: greedy */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = INT32_MIN;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > maxsum) maxsum = sum;
            if(sum <= 0) sum = 0;
        }
        return maxsum;
    }
};

/* method 3: divide and conquer */
class Solution {
public:
    struct Status {
        int lsum, rsum, msum, isum;
    }
    Status pushup(Status l, Status r) {
        int isum = l.isum + r.isum;
        int lsum = max(l.lsum, l.isum + r.lsum);
        int rsum = max(r.rsum, r.isum + l.rsum);
        int msum = max(max(l.msum, r.msum), l.rsum + r.lsum);
        return (Status) {lsum, rsum, msum, isum};
    }
    Status get(vector<int> &a, int l, int r) {
        if(l == r) return (Status){a[l], a[l], a[l], a[l]};
        int m = (l + r) >> 1;
        Status lsub = get(a, l, m);
        Status rsub = get(a, m + 1, r);
        return pushup(lsun, rsub);
    }
    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).msum;
    }
};