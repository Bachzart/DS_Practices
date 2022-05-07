/* method 1: sort */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        vector<int> dis(size);
        vector<int> indices(size);
        for(int i = 0; i < size; i++) {
            dis[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        }
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return dis[i] < dis[j]; });
        vector<vector<int>> ret;
        for(int i = 0; i < k; i++) {
            ret.push_back(points[indices[i]]);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return {points.begin(), points.begin() + k};
    }
};

/* method 2: heap */
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < k; i++) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
        }
        int size = points.size();
        for(int i = k; i < size; i++) {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if(dis < q.top().first) {
                q.pop();
                q.emplace(dis, i);
            }
        }
        vector<vector<int>> ret;
        while(!q.empty()) {
            ret.push_back(points[q.top().second]);
            q.pop();
        }
        return ret;
    }
};

/* method 3: quick sort */
class Solution {
    mt19937 gen{random_device{}()};
public:
    void random_select(vector<vector<int>>& points, int left, int right, int k) {
        int pivot_id = uniform_int_distribution<int>{left, right}(gen);
        int pivot = points[pivot_id][0] * points[pivot_id][0] + points[pivot_id][1] * points[pivot_id][1];
        swap(points[right], points[pivot_id]);
        int i = left - 1;
        for(int j = left; j < right; j++) {
            int dis = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if(dis <= pivot) {
                i++;
                swap(points[i], points[j]);
            }
        }
        i++;
        swap(points[i], points[right]);
        if(k < i - left + 1) random_select(points, left, i - 1, k);
        else if( k > i - left + 1) random_select(points, i + 1, right, k - (i - left + 1));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int size = points.size();
        random_select(points, 0, size - 1, k);
        return {points.begin(), points.begin() + k};
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1, points.end(), [](auto &a, auto &b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        return {points.begin(), points.begin() + k};
    }
};