/* hash, vesion 1 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<double, int> ht;
        int size = arr.size();
        for(int i = 0; i < size; i++) {
            ht[(double)arr[i]]++;
        }
        map<double, int>::iterator it = ht.begin();
        for(; it != ht.end(); it++) {
            int amount = it->second;
            for(int i = 0; i < amount; i++) {
                double tmp = it->first;
                if(tmp < 0) {
                    if(ht.find(tmp / 2) == ht.end() || ht.find(tmp / 2)->second == 0) return false;
                    ht[tmp / 2]--;
                } else {
                    if(ht.find(tmp * 2) == ht.end() || ht.find(tmp * 2)->second == 0) return false;
                    ht[tmp * 2]--;
                }
            }
        }
        return true;
    }
};

/* version 2 */
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> ht;
        for(int x: arr) {
            ht[x]++;
        }
        if(ht[0] % 2) return false;
        vector<int> keys(arr.size());
        for(auto &[x, _]: ht) {
            keys.push_back(x);
        }
        sort(keys.begin(), keys.end(), [](int a, int b) { return abs(a) < abs(b); });
        for(int x: keys) {
            if(ht[2 * x] < ht[x]) return false;
            ht[2 * x] -= ht[x];
        }
        return true;
    }
};