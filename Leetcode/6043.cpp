/* violent solution */
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

/* sort + binary search */
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        int size = points.size();
        vector<vector<int>> rec(110);
        for(auto &v: rectangles) {
            rec[v[1]].push_back(v[0]);
        }
        for(auto &v: rec) {
            sort(v.begin(), v.end());
        }
        vector<int> ret(size);
        for(int i = 0; i < size; i++) {
            int x = points[i][0], y = points[i][1];
            for(int j = y; j <= 100; j++) {
                if(!rec[j].empty()) {
                    ret[i] += rec[j].end() - (lower_bound(rec[j].begin(), rec[j].end(), x));
                }
            }
        }
        return ret;
    }
};

/* y-axis sort + binary search */
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[1] > b[1]; });
        int size = points.size();
        vector<int> indices(size);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return points[i][1] > points[j][1]; });
        vector<int> ans(size), arr;
        int i = 0;
        for(int id: indices) {
            int start = i;
            while(i < rectangles.size() && rectangles[i][1] >= points[id][1]) {
                arr.push_back(rectangles[i++][0]);
            }
            if(start < i) sort(arr.begin(), arr.end());
            ans[id] = arr.end() - lower_bound(arr.begin(), arr.end(), points[id][0]);
        }
        return ans;
    }
};

/* x-axis sort + binary search */
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[0] > b[0]; });
        int size = points.size();
        vector<int> indices(size);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return points[i][0] > points[j][0]; });
        vector<int> ans(size), cnt(101);
        int i = 0;
        for(int id: indices) {
            while(i < rectangles.size() && rectangles[i][0] >= points[id][0]) {
                ++cnt[rectangles[i++][1]];
            }
            ans[id] = accumulate(cnt.begin() + points[id][1], cnt.end(), 0);
        }
        return ans;
    }
};