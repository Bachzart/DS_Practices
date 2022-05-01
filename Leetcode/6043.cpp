class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> ret;
        int pointnums = points.size(), rectanglenums = rectangles.size();
        for(int i = 0; i < pointnums; i++) {
            int x = points[i][0], y = points[i][1], cnt = 0;
            for(int j = 0; j < rectanglenums; j++) {
                if(x <= rectangles[j][0] &&  y <= rectangles[j][1]) cnt++;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};