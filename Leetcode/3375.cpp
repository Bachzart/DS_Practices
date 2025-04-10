class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int, int> cnt;
        for(int i: nums) {
            if(i < k)
                return -1;
            ++cnt[i];
        }
        return cnt.count(k) == 0 ? cnt.size() : cnt.size() - 1;
    }
};