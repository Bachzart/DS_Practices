class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> ht;
        for(int i: nums)
            ht[i]++;
        vector<vector<int>> ret;
        int cnt = 0;
        while(cnt < nums.size()) {
            vector<int> ans;
            for(auto &[i, t]: ht) {
                if(t) {
                    ans.push_back(i);
                    --t;
                    ++cnt;
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};