/*
method 1: hash + greedy
*/
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> cnt;
        for(int i: answers)
            ++cnt[i];
        int ans = 0;
        for(auto &[x, t]: cnt) {
            ans += t;
            if(t % (x + 1) != 0)
                ans += (x + 1 - t % (x + 1));
        }
        return ans;
    }
};