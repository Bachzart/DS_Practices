/* method 1: use bit operation to compare every adjacent bits.*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int tmp = n;
        bool flag1 = tmp & 1, flag2;
        tmp >>= 1;
        for(; tmp; tmp >>= 1) {
            flag2 = tmp & 1;
            if(flag2 == flag1) break;
            else flag1 = flag2;
        }
        if(tmp) return false;
        else return true;
    }
};

/* method 2: use bit operation to judge whether it has alternating or not. */
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};