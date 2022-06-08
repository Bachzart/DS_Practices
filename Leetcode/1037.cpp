class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[2][0] - points[1][0], y1 = points[2][1] - points[2][1];
        int x2 = points[1][0] - points[0][0], y2 = points[1][1] - points[0][1];
        return x1 * y2 - x2 * y1 == 0;
    }
};