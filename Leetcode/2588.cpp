class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int, int> ht;
        ht[0] = 1;
        long long ret = 0;
        int mask = 0;
        for(int x: nums) {
            mask ^= x;
            ret += ht[mask];
            ht[mask]++;
        }
        return ret;
    }
};