/* violent solution */
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int boundry = 0, ret = 1;
        for(auto &i: nums) {
            if(i < 0) boundry += i;
        }
        if(boundry == 0) return ret;
        else {
            boundry = abs(boundry) + 1;
            for(int i = 1; i <= boundry; i++) {
                int sum = i, j = 0;
                for(; j < nums.size(); j++) {
                    sum += nums[j];
                    if(sum < 1) break;
                }
                if(j == nums.size() && sum >= 1) {
                    ret = i;
                    break;
                }
            }
            return ret;
        }
    }
};

/* binary search */
class Solution {
public:
    bool judge(int startvalue, vector<int>& nums) {
        for(int &i: nums) {
            startvalue += i;
            if(startvalue < 1) return false;
        }
        return true;
    }
    int minStartValue(vector<int>& nums) {
        int boundry = 0;
        for(auto &i: nums) {
            if(i < 0) boundry += i;
        }
        if(boundry == 0) return 1;
        else {
            int left = 1, right = abs(boundry) + 2;
            while(left < right) {
                int min = (left + right) / 2;
                if(judge(min, nums)) right = min;
                else left = min + 1;
            }
            return left;
        }
    }
};

/* greedy */
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minsum = 0, sum = 0;
        for(int &i: nums) {
            sum += i;
            minsum = min(minsum, sum);
        }
        minsum = abs(minsum);
        return minsum + 1;
    }
};
