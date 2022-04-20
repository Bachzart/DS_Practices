/* method 1 */
class Solution {
public:
    void dfs(vector<int>& ret, int cur, int end) {
        if(cur > end) return;
        ret.push_back(cur);
        for(int i = 0; i <= 9; i++) dfs(ret, cur * 10 + i, end);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for(int i = 1; i <= 9; i++) dfs(ret, i, n);
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret(n);
        int number = 1;
        for(int i = 0; i < n; i++) {
            ret[i] = number;
            if(number * 10 <= n) number *= 10;
            else {
                while(number % 10 == 9 || number + 1 > n) number /= 10;
                number++;
            }
        }
        return ret;
    }
};