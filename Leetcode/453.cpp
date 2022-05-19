/* violent solution: TLE */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0, size = nums.size();
        while(true) {
            int minnum = INT_MAX, maxnum = INT_MIN;
            for(int i = 0; i < size; i++) {
                if(minnum > nums[i]) minnum = nums[i];
                if(maxnum < nums[i]) maxnum = nums[i];
            }
            int diff = maxnum - minnum;
            if(diff == 0) break;
            else {
                for(int i = 0; i < size; i++) {
                    if(nums[i] != maxnum) nums[i] += diff;
                }
                cnt += diff;
            }
        }
        return cnt;
    }
};

/* math */
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = *min_element(nums.begin(), nums.end());
        int ret = 0;
        for(int i: nums) {
            ret += i - minnum;
        }
        return ret;
    }
};