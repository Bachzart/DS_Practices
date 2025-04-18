/*
hash + sliding window, version 1
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        int cnt = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0, j = -1; i < n; ++i) {
            while(j < n && cnt < k) {
                ++j;
                cnt += ht[nums[j]];
                ++ht[nums[j]];
            }
            if(cnt >= k) {
                ans += n - j;
            }
            cnt -= --ht[nums[i]];
        }
        return ans;
    }
};

/*
hash + sliding window, version 2

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        int cnt = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0, j = 0; i < n; ++i) {
            while(j < n && cnt < k) {
                ++ht[nums[j]];
                if(ht[nums[j]] >= 2)
                    cnt += ht[nums[j]] - 1;
                ++j;
            }
            if(cnt >= k) {
                ans += n - j + 1;
            }
            cnt -= --ht[nums[i]];
        }
        return ans;
    }
};

*/