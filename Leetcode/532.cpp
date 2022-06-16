/* sort + binary search + hash */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt = 0;
        if(k == 0) {
            unordered_map<int, int> mp;
            for(int i: nums) {
                mp[i]++;
            }
            for(auto &[_, times]: mp) {
                if(times >= 2) cnt++;
            }
        } else {
            set<int> s;
            for(int i: nums) {
                s.insert(i);
            }
            for(auto &i: s) {
                auto it = s.lower_bound(k + i);
                if(it != s.end() && (*it) == k + i) cnt++;
            }
        }
        return cnt;
    }
};

/* hash */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> ht;
        unordered_set<int> numpairs;
        for(int i: nums) {
            if(ht.count(i - k)) {
                numpairs.insert(i - k);
            }
            if(ht.count(i + k)) {
                numpairs.insert(i);
            }
            ht.insert(i);
        }
        return numpairs.size();
    }
};

/* two pointers */
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), y = 0, cnt = 0;
        for(int x = 0; x < n; x++) {
            if(x == 0 || nums[x] != nums[x - 1]) {
                while(y < n && (nums[y] < nums[x] + k || y <= x)) y++;
                if(y < n && nums[y] == nums[x] + k) cnt++;
            }
        }
        return cnt;
    }
};