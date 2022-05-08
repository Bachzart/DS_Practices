/* method 1: violent solution, enumrate all the lattice points of every circle. */
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        map<pair<int, int>, int> points;
        for(auto v: circles) {
            int l = v[0] + v[2], h = v[1] + v[2], r = v[2];
            int leftlowerx = v[0] - v[2], leftlowery = v[1] - v[2];
            for(int i = leftlowerx; i <= l; i++) {
                for(int j = leftlowery; j <= h; j++) {
                    int dis = (i - v[0]) * (i - v[0]) + (j - v[1]) * (j - v[1]);
                    if(dis <= r * r) points[make_pair(i, j)] = 1;
                }
            }
        }
        return points.size();
    }
};

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        map<pair<int, int>, int> points;
        for(auto v: circles) {
            int l = v[0] + v[2], h = v[1] + v[2], r = v[2];
            int leftlowerx = v[0] - v[2], leftlowery = v[1] - v[2];
            for(int i = leftlowerx; i <= l; i++) {
                for(int j = leftlowery; j <= h; j++) {
                    if(points.count(make_pair(i, j))) continue;
                    int dis = (i - v[0]) * (i - v[0]) + (j - v[1]) * (j - v[1]);
                    if(dis <= r * r) points[make_pair(i, j)] = 1;
                }
            }
        }
        return points.size();
    }
};

/* method 2: violent solutions, enum all the points and every point just need to be lattice point of one circle. */
class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int leftlowerxmin = INT_MAX, leftlowerymin = INT_MAX;
        int lmax = INT_MIN, hmax = INT_MIN;
        for(auto &v: circles) {
            int l = v[0] + v[2], h = v[1] + v[2];
            int leftlowerx = v[0] - v[2], leftlowery = v[1] - v[2];
            if(l > lmax) lmax = l;
            if(h > hmax) hmax = h;
            if(leftlowerx < leftlowerxmin) leftlowerxmin = leftlowerx;
            if(leftlowery < leftlowerymin) leftlowerymin = leftlowery;
        }
        map<pair<int, int>, int> latticepoints;
        for(int i = leftlowerxmin; i <= lmax; i++) {
            for(int j = leftlowerymin; j <= hmax; j++) {
                if(latticepoints.count(make_pair(i, j))) break;
                for(auto &v: circles) {
                    int dis = (i - v[0]) * (i - v[0]) + (j - v[1]) * (j - v[1]);
                    if(dis <= v[2] * v[2]) {
                        latticepoints[make_pair(i, j)] = 1;
                        break;
                    }
                }
            }
        }
        return latticepoints.size();
    }
};