class Solution {
public:
    bool isprime(int n) {
        if(n <= 1) return false;
        else {
            int sqr = sqrt(n);
            for(int i = 2; i <= sqr; i++) {
                if(n % i == 0) return false;
            }
            return true;
        }
    }
    long long factorial(int n) {
        long long ret = 1;
        for(int i = 2; i <= n; i++) {
            ret *= i;
            ret %= mod;
        }
        return ret;
    }
    int numPrimeArrangements(int n) {
        int numofprime = 0;
        for(int i = 1; i <= n; i++) {
            if(isprime(i)) numofprime++;
        }
        return (factorial(numofprime) * factorial(n - numofprime) % mod);
    }
private:
    const int mod = 1e9 + 7;
};