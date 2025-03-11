class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int first, second, third, n = nums.size();
        vector<vector<int>> ret;
        for(first = 0; first < n; ++first) {
            if(first != 0 && nums[first] == nums[first - 1])
                continue;
            third = n - 1;
            int target = -nums[first];
            for(second = first + 1; second < n; ++second) {
                if(second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                while(second < third && nums[second] + nums[third] > target)
                    --third;
                if(second == third)
                    break;
                if(nums[second] + nums[third] == target)
                    ret.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ret;
    }
};