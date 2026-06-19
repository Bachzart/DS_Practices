class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, cur = 0;
        for(int i: gain) {
            cur += i;
            ans = max(cur, ans);
        }
        return ans;
    }
};