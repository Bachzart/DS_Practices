class Solution {
public:
    int binaryGap(int n) {
        int cnt = 0, maxgap = 0, pre;
        for(int i = 0; n != 0; n >>= 1, i++) {
            if(n & 1) {
                cnt++;
                if(cnt != 1 && i - pre > maxgap) maxgap = i - pre;
                pre = i;
            }
        }
        return maxgap;
    }
};