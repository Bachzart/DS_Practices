class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        string s;
        for(int i: nums) {
            s = to_string(i);
            ans += (s.length() & 1) != 1;
        }
        return ans;
    }
};