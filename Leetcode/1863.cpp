/*
method 1: bit enum
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int Orsum = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            int t = 0;
            for(int i = 0; i < n; ++i) {
                if(mask & (1 << i))
                    t ^= nums[i];
            }
            Orsum += t;
        }
        return Orsum;
    }
};


/*
method 2: backtracking

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int Orsum = 0;
        function<void(int, int)> dfs = [&](int i, int t) {
            if(i == nums.size()) {
                Orsum += t;
                return;
            }
            dfs(i + 1, t);
            t ^= nums[i];
            dfs(i + 1, t);
        };
        dfs(0, 0);
        return Orsum;
    }
};

*/