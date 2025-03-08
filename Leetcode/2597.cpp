/*
method 1: bitwise enum
*/
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        for(int mask = 1; mask < (1 << n); ++mask) {
            vector<int> subset;
            for(int i = 0; i < n; ++i) {
                if(mask & (1 << i)) 
                    subset.push_back(nums[i]);
            }
            int m = subset.size();
            bool flag = true;
            for(int i = 0; i < m; ++i) {
                for(int j = i + 1; j < m; ++j) {
                    if(abs(subset[i] - subset[j]) == k) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) ++ans;
        }
        return ans;
    }
};


/*
method 2: dp

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> groups;
        for(int a: nums)
            ++groups[a % k][a];
        int ans = 1;
        for(auto &[_, g]: groups) {
            int m = g.size();
            vector<vector<int>> f(m, vector<int>(2, 0));
            f[0][0] = 1, f[0][1] = (1 << g.begin()->second) - 1;
            int i = 1;
            for(auto it = next(g.begin()); it != g.end(); it++, i++) {
                f[i][0] = f[i - 1][0] + f[i - 1][1];
                if(it->first - prev(it)->first == k) 
                    f[i][1] = f[i - 1][0] * ((1 << it->second) - 1);
                else 
                    f[i][1] = (f[i - 1][0] + f[i - 1][1]) * ((1 << it->second) - 1);
            }
            ans *= f[m - 1][0] + f[m - 1][1];
        }
        return ans - 1;
    }
};

*/

/*
method 3: backtracking + function object + lambda

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> cnt;
        function<void(int)> dfs = [&](int i) {
            if(i == nums.size()) {
                ++ans;
                return;
            }
            dfs(i + 1);
            if(cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0) {
                ++cnt[nums[i]];
                dfs(i + 1);
                --cnt[nums[i]];
            }
        };
        dfs(0);
        return ans - 1;
    }
};
*/

/*
method 3: backtracking

class Solution {
private:
    unordered_map<int, int> cnt;
    int n, ans;
public:
    void dfs(int i, vector<int>& nums, int &k) {
        if(i == n) {
            ++ans;
            return;
        }
        dfs(i + 1, nums, k);
        if(cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0) {
            ++cnt[nums[i]];
            dfs(i + 1, nums, k);
            --cnt[nums[i]];
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        n = nums.size(), ans = 0;
        dfs(0, nums, k);
        return ans - 1;
    }
};

*/