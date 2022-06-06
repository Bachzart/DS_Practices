class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        while(n != 1) {
            n = nums.size();
            vector<int> tmp;
            for(int i = 0; i < n / 2; i++) {
                int t;
                if(i % 2 == 0) t = min(nums[2 * i], nums[2 * i + 1]);
                else t = max(nums[2 * i], nums[2 * i + 1]);
                tmp.push_back(t);
            }
            nums = tmp;
        }
        return nums[0];
    }
};

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n;
        while(n != 1) {
            n = nums.size();
            vector<int> tmp;
            for(int i = 0; i < n / 2; i++) {
                int t;
                if(i % 2 == 0) t = min(nums[2 * i], nums[2 * i + 1]);
                else t = max(nums[2 * i], nums[2 * i + 1]);
                tmp.push_back(t);
            }
            nums = tmp;
        }
        return nums[0];
    }
};