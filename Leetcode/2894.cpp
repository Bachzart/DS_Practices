/*
method 1: math
*/
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int k = n / m;
        return n * (n + 1) / 2 - k * (k + 1) * m;
    }
};

/*
method 2: violent solutions
*/
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for(int i = 1; i <= n; ++i)
            if(i % m)
                ans += i;
            else
                ans -= i;
        return ans;
    }
};