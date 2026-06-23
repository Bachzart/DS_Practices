class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        constexpr int MOD = 1e9 + 7;
        int k = r - l + 1;

        vector<int> f0(k, 1);
        vector<int> f1(k, 1);
        vector<long long> s0(k + 1);
        vector<long long> s1(k + 1);
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < k; ++j) {
                s0[j + 1] = s0[j] + f0[j];
                s1[j + 1] = s1[j] + f1[j];
            }
            for(int j = 0; j < k; ++j) {
                f0[j] = s1[j] % MOD;
                f1[j] = (s0[k] - s0[j + 1]) % MOD;
            }
        }

        long long res0 = reduce(f0.begin(), f0.end(), 0LL);
        long long res1 = reduce(f1.begin(), f1.end(), 0LL);
        return (res0 + res1) % MOD;
    }
};