/* next_permutation */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        do{
            ret.push_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));
        return ret;
    }
};

/* dfs */
class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& nums, int first, int len) {
        if(first == len) {
            ret.push_back(nums);
            return;
        }
        for(int i = first; i < len; i++) {
            swap(nums[i], nums[first]);
            dfs(ret, nums, first + 1, len);
            swap(nums[i], nums[first]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(ret, nums, 0, nums.size());
        return ret;
    }
};