/*
method 1: sliding window + hash
*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> ht(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            while(j < n && cnt.size() < ht.size())
                ++cnt[nums[j++]];
            if(cnt.size() == ht.size())
                ans += n - j + 1;
            if(--cnt[nums[i]] == 0)
                cnt.erase(nums[i]);
        }
        return ans;
    }
};


/*
method 2: violent solutions

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int> cnt;
        for(int i: nums) 
            cnt.insert(i);
        for(int i = 0; i < n; ++i) {
            unordered_set<int> ht;
            for(int j = i; j < n; ++j) {
                ht.insert(nums[j]);
                if(ht.size() == cnt.size())
                    ++ans;
                else if(ht.size() > cnt.size())
                    break;
            }
        }
        return ans;
    }
};

*/