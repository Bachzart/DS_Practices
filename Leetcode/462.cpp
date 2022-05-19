/* sort + median */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int ret = 0, median = nums[size / 2];
        for(int &i: nums) {
            ret += abs(nums[i] - median);
        }
        return ret;
    }
};

/* median + quick sort */
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        int median = size / 2, ret = 0;
        nth_element(nums.begin(), nums.begin() + median, nums.end());
        for(int &i: nums) {
            ret += abs(i - nums[median]);
        }
        return ret;
    }
};