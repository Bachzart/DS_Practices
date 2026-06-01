class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int ans = 0, i;
        for(i = cost.size() - 1; i - 3 >= 0; i -= 3) {
            ans = ans + cost[i] + cost[i - 1];
        }
        if(i == 0) {
            ans += cost[i];
        } else if(i == 1 || i == 2) {
            ans = ans + cost[i] + cost[i - 1];
        }

        return ans;
    }
};
