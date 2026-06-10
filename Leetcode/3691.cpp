/*
Method 2: ST table and priority queue
*/
class ST {
    vector<vector<int>> st_min;
    vector<vector<int>> st_max;
public:
    ST(const vector<int>& a) {
        size_t n = a.size();
        int w = bit_width(n);
        st_min.resize(w, vector<int>(n));
        st_max.resize(w, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            st_min[0][i] = a[i];
            st_max[0][i] = a[i];
        }

        for(int i = 1; i < w; ++i) {
            for(int j = 0; j + (1 << i) <= n; ++j) {
                st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
                st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) const {
        int k = bit_width(static_cast<uint32_t>(r) - l) - 1;
        int mn = min(st_min[k][l], st_min[k][r - (1 << k)]);
        int mx = max(st_max[k][l], st_max[k][r - (1 << k)]);

        return mx - mn;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        ST st(nums);

        priority_queue<tuple<int, int, int>> pq;
        for(int i = 0; i < n; ++i) {
            pq.emplace(st.query(i, n), i, n);
        }

        long long ans = 0;
        while(k-- && get<0>(pq.top())) {
            auto [d, l, r] = pq.top();
            pq.pop();
            ans += d;
            pq.emplace(st.query(l, r - 1), l, r - 1);
        }

        return ans;
    }
};

/*
Method 1: violent solution, TLE

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int> res;
        for(int i = 0; i < sz; ++i) {
            int min = nums[i], max = nums[i];
            for(int j = i; j < sz; ++j) {
                if(nums[j] < min) min = nums[j];
                if(nums[j] > max) max = nums[j];
                res.push_back(max - min);
            }
        }
        sort(res.rbegin(), res.rend());
        long long ans = 0;
        if(sz == 1) return ans;
        for(int i = 0; i < k; ++i) {
            ans += res[i];
        }
        return ans;
    }
};

*/