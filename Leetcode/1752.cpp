/*
method 2: 
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int sz = nums.size();
        bool flag = nums[0] >= nums[sz - 1];
        for(int i = 1; i < sz; ++i) {
            if(nums[i - 1] > nums[i]) {
                if(!flag) {
                    return false;
                }
                flag = false;
            }
        }
        return true;
    }
};

/*
method 1: violent solution

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> src = nums;
        sort(src.begin(), src.end());
        int sz = nums.size();
        bool flag = true;
        for(int i = 0; i < sz; ++i) {
            flag = true;
            for(int j = 0; j < sz; ++j) {
                if(src[(j + i) % sz] != nums[j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) break;
        }
        return flag;
    }
};

*/