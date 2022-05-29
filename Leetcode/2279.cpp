/* struct + sort + greedy */
class Solution {
public:
    struct package{
        long long remain, size, now;
        package(): remain(0), size(0), now(0){}
    };
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        package pak[n];
        for(int i = 0; i < n; i++) {
            pak[i].size = capacity[i];
            pak[i].now = rocks[i];
            pak[i].remain = pak[i].size - pak[i].now;
        }
        sort(pak, pak + n, [](package a, package b) { return a.remain < b.remain; });
        int cnt = 0;
        long long addition = additionalRocks;
        for(int i = 0; i < n; i++) {
            if(pak[i].remain != 0) {
                additionalRocks -= pak[i].remain;
                if(additionalRocks >= 0) cnt++;
                else break;
            } else if(pak[i].remain == 0) cnt++;
        }
        return cnt;
    }
};

/* multiset + greedy */
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        set<int> remains;
        int n = capacity.size();
        for(int i = 0; i < n; i++) {
            remains.insert(capacity[i] - rocks[i]);
        }
        int cnt = 0;
        for(auto &i: remains) {
            if(i != 0) {
                additionalRocks -= i;
                if(additionalRocks >= 0) cnt++;
                else break;
            } else if(i == 0) cnt++;
        }
        return cnt;
    }
};

/* vector + sort + greedy */
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remains;
        int n = capacity.size();
        for(int i = 0; i < n; i++) {
            remains.push_back(capacity[i] - rocks[i]);
        }
        sort(remains.begin(), remains.end());
        int cnt = 0;
        for(auto &i: remains) {
            if(i != 0) {
                additionalRocks -= i;
                if(additionalRocks >= 0) cnt++;
                else break;
            } else if(i == 0) cnt++;
        }
        return cnt;
    }
};