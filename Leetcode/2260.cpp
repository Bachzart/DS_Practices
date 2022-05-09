/* hash + violent search */
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        map<int, vector<int>> ht;
        for(int i = 0; i < size; i++) {
            ht[cards[i]].push_back(i);
        }
        int minimum = INT_MAX;
        for(auto &[x, v]: ht) {
            if(v.size() > 1) {
                int tmp = v[1] - v[0] + 1, s = v.size();
                for(int i = 1; i < s - 1; i++) {
                    if(tmp > v[i + 1] - v[i]) tmp = v[i + 1] - v[i] + 1;
                }
                if(minimum > tmp) minimum = tmp;
            }
        }
        if(minimum == INT_MAX) return -1;
        else return minimum;
    }
};

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        unordered_map<int, vector<int>> ht;
        for(int i = 0; i < size; i++) {
            ht[cards[i]].push_back(i);
        }
        int minimum = INT_MAX;
        for(auto &[x, v]: ht) {
            if(v.size() > 1) {
                int tmp = v[1] - v[0] + 1, s = v.size();
                for(int i = 1; i < s - 1; i++) {
                    if(tmp > v[i + 1] - v[i]) tmp = v[i + 1] - v[i] + 1;
                }
                if(minimum > tmp) minimum = tmp;
            }
        }
        if(minimum == INT_MAX) return -1;
        else return minimum;
    }
};

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        unordered_map<int, set<int>> ht1;
        unordered_map<int, int> ht2;
        for(int i = 0; i < size; i++) {
            if(ht2.count(cards[i])) ht1[cards[i]].insert(i - ht2[cards[i]] + 1);
            ht2[cards[i]] = i;
        }
        int minimum = INT_MAX;
        for(auto &[x, s]: ht1) {
            if(minimum > *s.begin()) minimum = *s.begin();
        }
        if(minimum == INT_MAX) return -1;
        else return minimum;
    }
};

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        unordered_map<int, int> ht;
        int minimum = INT_MAX;
        for(int i = 0; i < size; i++) {
            if(ht.count(cards[i])) minimum = min(minimum, i - ht[cards[i]] + 1);
            ht[cards[i]] = i;
        }
        if(minimum == INT_MAX) return -1;
        else return minimum;
    }
};

/* sliding window */
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int size = cards.size();
        unordered_set<int> ht;
        int left, right, ans;
        left = right = 0;
        ans = INT_MAX;
        while(right < size) {
            while(ht.count(cards[right])) {
                ans = min(ans, right - left + 1);
                ht.erase(cards[left]);
                left++;
            }
            ht.insert(cards[right]);
            right++;
        }
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};