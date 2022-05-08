/* method 1: violent solution */
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int fsize = flowers.size(), psize = persons.size();
        unordered_map<int, int> ht;
        for(int i = 0; i < fsize; i++) {
            int start = flowers[i][0], end = flowers[i][1];
            while(start <= end) {
                ht[start++]++;
            }
        }
        vector<int> ret;
        for(int i = 0; i < psize; i++) {
            ret.push_back(ht[persons[i]]);
        }
        return ret;
    }
};

/* method 2: difference */
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> ht;
        for(auto &f: flowers) {
            ht[f[0]]++;
            ht[f[1] + 1]--;
        }
        int psize = persons.size();
        vector<int> ans(psize);
        int index = 0;
        for(int &i: persons) {
            int sum = 0;
            auto it = ht.begin();
            while(it != ht.end() && it->first <= i) {
                sum += it++->second;
            }
            ans[index++] = sum;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> ht;
        for(auto &f: flowers) {
            ht[f[0]]++;
            ht[f[1] + 1]--;
        }
        int psize = persons.size();
        vector<int> ans(psize);
        int index = 0;
        for(int &i: persons) {
            int sum = 0;
            auto it = ht.begin();
            while(it != ht.end() && it->first <= i) {
                sum += it++->second;
            }
            ans[index++] = sum;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> ht;
        for(auto &f: flowers) {
            ht[f[0]]++;
            ht[f[1] + 1]--;
        }
        int psize = persons.size();
        vector<int> ans(psize);
        vector<int> indices(psize);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int i, int j) { return persons[i] < persons[j]; });
        int sum = 0;
        auto it = ht.begin();
        for(int &i: indices) {
            while(it != ht.end() && it->first <= persons[i]) {
                sum += it++->second;
            }
            ans[i] = sum;
        }
        return ans;
    }
};

/* method 3: binary search */
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        int fsize = flowers.size();
        vector<int> starts(fsize), ends(fsize);
        for(auto &v: flowers) {
            starts.push_back(v[0]);
            ends.push_back(v[1]);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int psize = persons.size();
        vector<int> ans(psize);
        for(int i = 0; i < psize; i++) {
            ans[i] = (upper_bound(starts.begin(), starts.end(), persons[i]) - starts.begin()) - 
                     (lower_bound(ends.begin(), ends.end(), persons[i]) - ends.begin());
        }
        return ans;
    }
};