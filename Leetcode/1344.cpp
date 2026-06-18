/*
Method 1: math
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = abs(hour * 30 + minutes * 0.5 - minutes * 6.0);
        return min(a, 360 - a);
    }
};