/* sort */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> tmp(heights);
        sort(tmp.begin(), tmp.end());
        int n = heights.size(), cnt = 0;
        for(int i = 0; i < n; i++) {
            if(heights[i] != tmp[i]) cnt++;
        }
        return cnt;
    }
};

/* count sort */
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int maxele = *max_element(heights.begin(), heights.end());
        vector<int> indices(maxele + 1);
        for(int i: heights) {
            ++indices[i];
        }
        int cnt = 0, index = 0;
        for(int i = 1; i <= maxele; ++i) {
            for(int j = 1; j <= indices[i]; ++j) {
                if(heights[index] != i) ++cnt;
                ++index;
            }
        }
        return cnt;
    }
};