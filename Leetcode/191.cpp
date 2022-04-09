/* method 1 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
};

/* method 2 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
};

/* method 3 */
class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};