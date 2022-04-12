/* method 1 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double k, b, diff1, diff2;
        diff1 = coordinates[1][1] - coordinates[0][1];
        diff2 = coordinates[1][0] - coordinates[0][0];
        if(diff1 == 0) {
            for(int i = 0; i < coordinates.size() - 1; i++) {
                if(coordinates[i][1] != coordinates[i + 1][1]) return false;
            }
        } else if(diff2 == 0) {
            for(int i = 0; i < coordinates.size() - 1; i++) {
                if(coordinates[i][0] != coordinates[i + 1][0]) return false;
            }
        } else {
            k = diff1 / diff2;
            b = coordinates[0][1] - k * coordinates[0][0];
            for(int i = 2; i < coordinates.size(); i++) {
                if(coordinates[i][1] != b + k * coordinates[i][0]) return false;
            }
        }
        return true;
    }
};

/* method 2 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int deltax = coordinates[0][0], deltay = coordinates[0][1];
        for(int i = 0; i < coordinates.size(); i++) {
            coordinates[i][0] -= deltax;
            coordinates[i][1] -= deltay;
        }
        int A = coordinates[1][1], B = -coordinates[1][0];
        for(int i = 2; i < coordinates.size(); i++) {
            if(coordinates[i][0] * A + coordinates[i][1] * B != 0) return false;
        }
        return true;
    }
};

/* method 3 */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        for(int i = 2; i < coordinates.size(); i++) {
            if(
                (coordinates[i][0] - coordinates[0][0]) * 
                (coordinates[i][1] - coordinates[1][1]) !=
                (coordinates[i][0] - coordinates[1][0]) *
                (coordinates[i][1] - coordinates[0][1])
                ) return false;
        }
        return true;
    }
};