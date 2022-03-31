/* method 1 */
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        string tmp;
        for(; left <= right; left++) {
            tmp = to_string(left);
            if(tmp.find("0") != string::npos) continue;
            bool flag = true;
            for(int i = 0; i < tmp.length(); i++) {
                if(left % (tmp[i] - '0') != 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) ret.push_back(left);
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    bool isselfdivided(int n) {
        int tmp = n, digit;
        while(tmp) {
            digit = tmp % 10;
            if(digit == 0 || n % digit != 0) return false;
            tmp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        string tmp;
        for(; left <= right; left++) {
            if(isselfdivided(left)) ret.push_back(left);
        }
        return ret;
    }
};