/* calculate slope */
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int size = stockPrices.size();
        if(size == 1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
        int cnt = 1;
        long double prek = (long double)(stockPrices[1][1] - stockPrices[0][1]) / (stockPrices[1][0] - stockPrices[0][0]);
        long double curk;
        for(int i = 2; i < size; i++) {
            curk = (long double)(stockPrices[i][1] - stockPrices[i - 1][1]) / (stockPrices[i][0] - stockPrices[i - 1][0]);
            if(curk != prek) cnt++;
            prek = curk;
        }
        return cnt;
    }
};

/* math vector */
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int size = stockPrices.size();
        if(size == 1) return 0;
        sort(stockPrices.begin(), stockPrices.end());
        int cnt = 1;
        for(int i = 2; i < size; i++) {
            long long x1 = stockPrices[i][0] - stockPrices[i - 1][0], y1 = stockPrices[i][1] - stockPrices[i - 1][1];
            long long x2 = stockPrices[i - 1][0] - stockPrices[i - 2][0], y2 = stockPrices[i - 1][1] - stockPrices[i - 2][1];
            if(y1 * x2 != y2 * x1) cnt++;
        }
        return cnt;
    }
};