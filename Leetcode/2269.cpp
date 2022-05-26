/* string */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int len = str.length(), ret = 0;
        for(int i = 0; i <= len - k; i++) {
            string tmp = str.substr(i, k);
            int t = stoi(tmp);
            if(t != 0 && num % t == 0) ret++;
        } 
        return ret;
    }
};

/* math */
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        long long ret = 0, mask = pow(10, k);
        for(int x = num; x >= mask / 10; x /= 10) {
            int tmp = x % mask;
            if(tmp != 0 && num % tmp == 0) ret++;
        }
        return ret;
    }
};