class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> label(n);
        int cur_label = 0, ans = -1;
        for(int i = 0; i < n; ++i) {
            if(label[i])
                continue;
            int pos = i, start_label = cur_label;
            while(pos != -1) {
                ++cur_label;
                if(label[pos]) {
                    if(label[pos] > start_label) 
                        ans = max(ans, cur_label - label[pos]);
                    break;
                }
                label[pos] = cur_label;
                pos = edges[pos];
            }
        }
        return ans;
    }
};