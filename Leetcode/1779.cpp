class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minmd = 0x3fffffff, index = -1;
        for(int i = 0; i < points.size(); i++) {
            if(points[i][0] == x && points[i][1] == y) return i;
            else if(points[i][0] == x || points[i][1] == y) {
                int tmp = abs(x - points[i][0]) + abs(y - points[i][1]);
                if(tmp < minmd) {
                    minmd = tmp;
                    index = i;
                }
            }
        }
        return index;
    }
};