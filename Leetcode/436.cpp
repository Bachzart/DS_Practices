/* sort + binary search */
class Solution {
public:
    map<int, int> startindex;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        for(int i = 0; i < size; i++) {
            int x = intervals[i][0];
            startindex[x] = i;
        }
        vector<int> ret(size);
        if(size == 1) {
            ret[0] = -1;
        } else {
            for(int i = 0; i < size; i++) {
                int y = intervals[i][1];
                auto pos = startindex.lower_bound(y);
                if(pos == startindex.end()) ret[i] = -1;
                else ret[i] = pos->second;
            }
        }
        return ret;
    }
};

class Solution {
public:
    map<int, int> startindex;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        for(int i = 0; i < size; i++) {
            int x = intervals[i][0];
            startindex[x] = i;
        }
        vector<int> ret(size, -1);
        for(int i = 0; i < size; i++) {
            int y = intervals[i][1];
            auto pos = startindex.lower_bound(y);
            if(pos != startindex.end()) ret[i] = pos->second;
        }
        return ret;
    }
};

/* two pointers + sort */
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<pair<int, int>> startindices;
        vector<pair<int, int>> endindices;
        for(int i = 0; i < size; i++) {
            startindices.push_back({intervals[i][0], i});
            endindices.push_back({intervals[i][1], i});
        }
        sort(startindices.begin(), startindices.end());
        sort(endindices.begin(), endindices.end());
        vector<int> ret(size, -1);
        for(int i = 0, j = 0; i < size && j < size; i++) {
            while(j < size && endindices[i].first > startindices[j].first) j++;
            if(j < size) {
               ret[endindices[i].second] = startindices[j].second;
            }
        }
        return ret;
    }
};