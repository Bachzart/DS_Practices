class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> ht;
        for(auto &v: dominoes) {
            if(ht.count({v[1], v[0]})) 
                ++ht[{v[1], v[0]}];
            else
                ++ht[{v[0], v[1]}];
        }
        int ans = 0;
        for(auto &[_, t]: ht) {
            cout << t << endl;
            ans += t * (t - 1) / 2;
        }
        return ans;
    }
};