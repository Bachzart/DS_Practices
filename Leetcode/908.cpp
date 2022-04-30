class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = 10e5, max = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(min > nums[i]) min = nums[i];
            if(max < nums[i]) max = nums[i];
        }
        max -= k, min += k;
        if(min >= max) return 0;
        else return max - min;
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = 10e5, max = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(min > nums[i]) min = nums[i];
            if(max < nums[i]) max = nums[i];
        }
        int diff = max - min;
        if(diff <= 2 * k) return 0;
        else return diff - 2 * k;
    }
};

class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int Min = *min_element(nums.begin(), nums.end());
        int Max = *max_element(nums.begin(), nums.end());
        int diff = Max - Min;
        if(diff <= 2 * k) return 0;
        else return diff - 2 * k;
    }
};