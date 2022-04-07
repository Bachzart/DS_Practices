/* method 1 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), max = 0;
        vector<int> profit(size);
        for(int i = 0; i < size; i++) {
            int index = i, tmax = prices[i];
            for(int j = index + 1; j < size; j++) {
                if(tmax < prices[j]) {
                    tmax = prices[j];
                    index = j;
                }
            }
            if(index == i) profit[i] = -1;
            else profit[i] = prices[index] - prices[i];
            if(profit[i] > max) max = profit[i];
        }
        return max;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size(), ans = 0;
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};

/* method 2 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size(), ans = 0;
        vector<int> dp(days);
        dp[0] = prices[0];
        for(int i = 1; i < days; i++) {
            dp[i] = min(dp[i - 1], prices[i]);
            ans = max(ans, prices[i] - dp[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size(), ans = 0, minprice = prices[0];
        for(int i = 1; i < days; i++) {
            minprice = min(minprice, prices[i]);
            ans = max(ans, prices[i] - minprice);
        }
        return ans;
    }
};