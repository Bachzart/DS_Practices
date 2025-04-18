/*
method 1: hash + math, not good.
*/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ht;
        for(int i = 0; i < n; ++i)
            ++ht[nums[i] - i];
        long long ans = 0;
        int rep = 0;
        for(auto &[_, t]: ht) {
            ans += t * (n - t - pre);
            rep += t;
        }
        return ans;
    }
};


/* method 2: hash
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> cnt;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int x = nums[i] - i;
            ans += i - cnt[x];
            ++cnt[x];
        }
        return ans;
    }
};
*/