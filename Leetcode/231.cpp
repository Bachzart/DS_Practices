/* method 1 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i = 0, tmp;
        while(true) {
            tmp = pow(2, i);
            if(tmp == n) return true;
            else if(tmp > n) return false;
            i++;
        }
    }
};

/* method 2 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0 ? true : false;
    }
};