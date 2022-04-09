class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0, digit;
        do {
            digit = n % 10;
            n /= 10;
            product *= digit;
            sum += digit;
        } while(n);
        return product - sum;
    }
};