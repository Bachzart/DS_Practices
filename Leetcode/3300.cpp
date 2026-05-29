class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i: nums) {
            int temp = 0;
            while(i > 0) {
                temp += i % 10;
                i /= 10;
            }
            ans = min(ans, temp);
        }
        return ans;
    }
};