/*
method 1: hash + traversal in the reverse order
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool ht[105] = {false};
        for(int i = nums.size() - 1; i >= 0; --i) {
            if(ht[nums[i]])
                return i / 3 + 1;
            ht[nums[i]] = true;
        }
        return 0;
    }
};


/*
method 2: hash + simulation

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n == 1)
            return ans;
        int cnt[105] = {0};
        for(int i: nums)
            ++cnt[i];
        auto check = [&]() -> bool {
            for(int t: cnt)
                if(t > 1)
                    return true;
            return false;
        };
        int idx = 0;
        while(check()) {
            ++ans;
            int t = 0;
            while(idx < n && t < 3) {
                 --cnt[nums[idx++]];
                 ++t;
            }
        }
        return ans;
    }
};

*/