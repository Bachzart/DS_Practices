/* bit operation + hash */
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int cnt[24] = {0};
        int n = candidates.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 24; j++) {
                if((1 << j) & candidates[i]) cnt[j]++;
            }
        }
        int ret = 0;
        for(int i = 0; i < 24; i++) {
            ret = max(ret, cnt[i]);
        }
        return ret;
    }
};