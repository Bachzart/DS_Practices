class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        auto check = [&](int n) {
            string s = to_string(n);
            int len = s.length();
            if(len & 1)
                return false;
            int diff = 0;
            for(int i = 0; i < len / 2; ++i) 
                diff += s[i] - s[len - i - 1];
            return diff == 0;
        };
        int ans = 0;
        while(low <= high) {
            if(check(low++))
                ++ans;
        }
        return ans;
    }
};