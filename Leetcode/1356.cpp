/* method 1 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int size = arr.size(), maxcount = 0;
        vector<vector<int>> res(14, vector<int>());
        for(int i = 0; i < size; i++) {
            int tmp = __builtin_popcount(arr[i]);
            res[tmp].push_back(arr[i]);
            if(tmp > maxcount) maxcount = tmp;
        }
        vector<int> ret;
        for(int i = 0; i <= maxcount; i++) {
            sort(res[i].begin(), res[i].end());
            for(int j: res[i]) {
                ret.push_back(j);
            }
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int size = arr.size();
        vector<int> bits(10001, 0);
        for(int i = 0; i < size; i++) {
            bits[arr[i]] = __builtin_popcount(arr[i]);
        }
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if(bits[a] != bits[b]) return bits[a] < bits[b];
            else return a < b;
        });
        return arr;
    }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int size = arr.size();
        vector<int> bits(10001, 0);
        for(int i = 1; i <= 10000; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            if(bits[a] != bits[b]) return bits[a] < bits[b];
            else return a < b;
        });
        return arr;
    }
};