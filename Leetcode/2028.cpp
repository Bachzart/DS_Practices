/* method 1: simulate the process */
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int diff = mean * (n + size);
        for(int i = 0; i < size; i++) diff -= rolls[i];
        if(n > diff || diff > 6 * n) return {};
        int number = diff / n, remains = diff % n;
        vector<int> ret(n);
        for(int i = 0; i < n ; i++) {
            ret[i] = number + (i < remains ? 1 : 0);
        }
        return ret;
    }
};

/* method 2: greedy algorithm */
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int diff = mean * (n + size);
        for(int i = 0; i < size; i++) diff -= rolls[i];
        if(n > diff || diff > 6 * n) return {};
        vector<int> ret;
        while(n) {
            int tmp = diff / n;
            if(n == 1) ret.push_back(diff);
            else {
                ret.push_back(tmp);
                diff -= tmp;
            }
            n--;
        }
        return ret;
    }
};