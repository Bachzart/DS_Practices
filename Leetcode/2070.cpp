class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto&& item1, auto&& item2) {
            return item1[0] < item2[0];
        });
        int n = items.size();
        for(int i = 1; i < n; ++i) 
            items[i][1] = max(items[i][1], items[i - 1][1]);
        auto f = [&](int q) -> int {
            int left = 0, right = n;
            while(left < right) {
                int mid = left + (right - left) / 2;
                if(items[mid][0] > q) 
                    right = mid;
                else 
                    left = mid + 1;
            }
            if(left == 0)
                return 0;
            else 
                return items[left - 1][1];
        };
        vector<int> ret;
        for(int q: queries) 
            ret.push_back(f(q));
        return ret;
    }
};