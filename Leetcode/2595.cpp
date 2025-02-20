class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even, odd, i;
        even = odd = i = 0;
        for(; n; i++, n >>= 1) {
            if(n & 1)
                if(i % 2)
                    odd++;
                else
                    even++;
        }
        return {even, odd};
    }
};