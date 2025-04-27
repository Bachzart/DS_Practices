/*
method 1: use multiplication
*/
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; ++i) {
            if((nums[i] + nums[i + 2]) * 2 == nums[i + 1])
                ++ans;
        }
        return ans;
    }
};

/*
method 2: use division

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; ++i) {
            if(1.0 * nums[i] + nums[i + 2] == nums[i + 1] / 2.0) 
                ++ans;
        }
        return ans;
    }
};

*/