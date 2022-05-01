class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int size = nums.size();
        vector<int> cnt(1005), ret;
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < nums[i].size(); j++) {
                cnt[nums[i][j]]++;
            }
        }
        for(int i = 0; i < 1005; i++) {
            if(cnt[i] == size) ret.push_back(i);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int size = nums.size();
        map<int, int> cnt;
        for(auto v: nums) {
            for(int x: v) cnt[x]++;
        }
        vector<int> ret;
        for(auto [key, val]: cnt) {
            if(val == size) ret.push_back(key);
        }
        return ret;
    }
};
