/*
method 1: backtracking
*/
class Solution {
private:
    vector<vector<int>> ret;
    vector<int> Nums;
public:
    void dfs(int i, vector<int> ans) {
        if(i == Nums.size()) {
            ret.push_back(ans);
            return;
        }
        ans.push_back(Nums[i]);
        dfs(i + 1, ans);
        ans.pop_back();
        dfs(i + 1, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        Nums = nums;
        vector<int> ans;
        dfs(0, ans);
        return ret;
    }
};

/*
method 2: bit enum

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> t;
        vector<vector<int>> ret;
        int n = nums.size();
        for(int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for(int i = 0; i < n; ++i) {
                if(mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ret.push_back(t);
        }
        return ret;
    }
};
*/
