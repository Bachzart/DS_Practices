/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */

class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        int m = blacklist.size();
        bound = n - m;
        unordered_set<int> black;
        for(int b: blacklist) {
            if(b >= bound) black.insert(b);
        }
        int w = bound;
        for(int b: blacklist) {
            if(b < bound) {
                while(bound.count(w)) ++w;
                black2white[b] = w++;
            }
        }
    }
    
    int pick() {
        int x = rand() % bound;
        return black2white.count(x) ? black2white[x] : x;
    }
private:
    unordered_map<int, int> black2white;
    int bound;
};
