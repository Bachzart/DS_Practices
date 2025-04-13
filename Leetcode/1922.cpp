/*
method 1: math
*/
class Solution {
public:
    const int MOD = 1e9 + 7;
    int countGoodNumbers(long long n) {
        long long ans = 1;
        if(n & 1)
            ans = 5;
        long long factor = 20;
        n >>= 1;
        while(n) {
            if(n & 1) 
                ans = ans * factor % MOD;
            factor = factor * factor % MOD;
            n >>= 1;
        }
        return ans;
    }
};



/*
method 1: violent solution, TLE

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans = 1;
        const long long MOD = 1e9 + 7;
        for(long long i = 0; i < n; ++i) {
            if(i & 1)
                ans = (ans * 4) % MOD;
            else
                ans = (ans * 5) % MOD;
        }
        return ans;
    }
};

*/