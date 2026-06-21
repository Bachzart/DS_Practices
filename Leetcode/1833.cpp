class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> counts(100005);
        int maxPrice = 0;
        for(int i: costs) {
            counts[i]++;
            maxPrice = max(maxPrice, i);
        }
        int ans = 0;
        for(int i = 1; i <= maxPrice && i <= coins; ++i) {
            int num = min(counts[i], coins / i);
            coins -= i * num;
            ans += num;
        }
        return ans;
    }
};