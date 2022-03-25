/* The number of trailing zeroes is the number of the five. */
/* method 1: calculate directly */
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0, tmp;
        for(int i = 5; i <= n; i += 5) {
            tmp = i;
            while(tmp % 5 == 0) {
                tmp /= 5;
                cnt++;
            }
        }
        return cnt;
    }
};

/* method 2: How to get the number of factors? n / factors = x, the x is the number of factors. */
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n) {
            n /= 5;
            cnt += n;
        }
        return cnt;
    }
};
