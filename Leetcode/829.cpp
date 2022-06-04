class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int k = 1; k * k < 2 * n; k++) {
            if (2 * n % k == 0 && (2 * n / k - k + 1) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};