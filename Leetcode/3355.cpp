/*
method 1: prefix sum + differential array
*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for(auto &v: queries) {
            ++diff[v[0]];
            --diff[v[1] + 1];
        }
        int presum = 0;
        for(int i = 0; i < n; ++i) {
            presum += diff[i];
            if(nums[i] > presum) 
                return false;
        }
        return true;
    }
};


/*
method 2: hash, TLE

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cnt(n);
        for(auto &v: queries) {
            for(int i = v[0]; i <= v[1]; ++i)
                ++cnt[i];
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] > cnt[i])
                return false;
        }
        return true;
    }
};

*/