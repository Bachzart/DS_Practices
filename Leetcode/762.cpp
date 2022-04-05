/* method 1 */
class Solution {
public:
    bool isprime(int n) {
        if(n <= 1) return false;
        else {
            for(int i = 2; i <= sqrt(n); i++) {
                if(n % i == 0) return false;
            }
            return true;
        }
    }
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        for( ; left <= right; left++) {
            int tmp = left, cnt0 = 0;
            while(tmp) {
                tmp &= (tmp - 1);
                cnt0++;
            }
            if(isprime(cnt0)) ret++;
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ret = 0;
        for( ; left <= right; left++) {
            if((1 << __builtin_popcount(left)) & 665772) ret++;
        }
        return ret;
    }
};