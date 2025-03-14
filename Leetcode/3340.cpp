class Solution {
public:
    bool isBalanced(string num) {
        int s = 0, sign = 1;
        for(char c: num) {
            s += (c - '0') * sign;
            sign = -sign;
        }
        return s == 0;
    }
};