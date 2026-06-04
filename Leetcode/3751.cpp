/*
method 1: violent solution, AC.
*/
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        auto check = [](int num) -> int {
            string s = to_string(num);
            int ret = 0;
            if(s.length() <= 2) return ret;
            for(int i = 1; i < s.length() - 1; ++i) {
                ret += ((s[i - 1] < s[i] && s[i] > s[i + 1]) ||
                        (s[i - 1] > s[i] && s[i] < s[i + 1]));
            }
            return ret;
        };
        while(num1 <= num2) {
            ans += check(num1++);
        }
        return ans;
    }
};