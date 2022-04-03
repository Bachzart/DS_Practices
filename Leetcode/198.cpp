/* 1 dimension dp */
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[105], size = nums.size();
        if(size == 1) return nums[0];
        dp[size - 1] = nums[size - 1], dp[size - 2] = nums[size - 2];
        int Max = dp[size - 1] > dp[size - 2] ? dp[size - 1] : dp[size - 2];
        if(size == 2) return Max;
        dp[size - 3] = nums[size - 3] + dp[size - 1];
        Max = Max > dp[size - 3] ? Max : dp[size - 3];
        for(int i = size - 4; i >= 0; i--) {
            dp[i] = nums[i] + max(dp[i + 2], dp[i + 3]);
            if(dp[i] > Max) Max = dp[i];
        }
        return Max;
    }
};

/* 1 dimension dp */
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        int dp[105];
        dp[0] = nums[0], dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};

/* 2 dimension dp */
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[105][2], size = nums.size();
        dp[0][0] = nums[0], dp[0][1] = 0;
        for(int i = 1; i < size; i++) {
            dp[i][0] = dp[i - 1][1] + nums[i];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        return max(dp[size - 1][0], dp[size - 1][1]);
    }
};