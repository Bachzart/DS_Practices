#define mod 1000000007
class Solution {
public:
    int fib(int n) {
        int fibonacci[105] = {0};
        fibonacci[1] = 1;
        for(int i = 2; i <= n; i++) {
            fibonacci[i] = (fibonacci[i - 1] + fibonacci[i - 2]) % mod;
        }
        return fibonacci[n];
    }
};

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        else if(n == 1) return 1;
        else return fib(n - 1) + fib(n - 2);
    }
};