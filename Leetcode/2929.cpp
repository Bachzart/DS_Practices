/*
method 1: math
*/
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto f = [&](int x) -> long long {
            if(x < 0)
                return 0;
            return 1LL * x * (x - 1) / 2;
        };
        long long ans = 0;
        ans += f(n + 2) - 3 * f(n - (limit + 1) + 2) \
                    + 3 * f(n - (limit + 1) * 2 + 2) \
                    - f(n - (limit + 1) * 3 + 2);
        return ans;
    }
};


/*
method 2: enumeration

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int border = min(limit, n);
        for(int first = 0; first <= border; ++first) {
            int r = min(limit, n - first);
            int l = max(0, n - first - limit);
            if(l <= r)
                ans += r - l + 1;
        }
        return ans;
    }
};
*/