/*
method: sort + math
*/
class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2])
            return "none";
        else if(nums[0] == nums[2])
            return "equilateral";
        else if(nums[0] != nums[1] && nums[1] != nums[2])
            return "scalene";
        else
            return "isosceles";
    }
};

/*
method: just use math

class Solution {
public:
    string triangleType(vector<int>& nums) {
        string ans = "none";
        if(nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])
            return ans;
        if(nums[0] != nums[1] && nums[0] != nums[2] && nums[1] != nums[2])
            ans = "scalene";
        else if(nums[0] == nums[1] && nums[1] == nums[2])
            ans = "equilateral";
        else
            ans = "isosceles";
        return ans;
    }
};
*/