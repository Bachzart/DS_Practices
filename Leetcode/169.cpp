class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int cnt = 0;
        for(int n: nums) {
            if(n == candidate)
                ++cnt;
            else if(--cnt < 0) {
                candidate = n;
                cnt = 1;
            }
        }
        return candidate;
    }
};