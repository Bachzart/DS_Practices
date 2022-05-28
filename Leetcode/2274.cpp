/* violent solution + hash, TLE. */
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int size = special.size();
        unordered_set<int> ht;
        for(int &i: special) {
            ht.insert(i);
        }
        int maxstairs = 0;
        while(bottom <= top) {
            while(ht.count(bottom) && bottom < top) bottom++;
            if(bottom == top) break;
            int i = bottom + 1;
            while(i <= top && !ht.count(i)) i++;
            maxstairs = max(maxstairs, i - bottom);
            bottom = i;
        }
        return maxstairs;
    }
};

/* sort */
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int size = special.size();
        vector<int> tmp = special;
        sort(tmp.begin(), tmp.end());
        if(tmp[size - 1] != top) {
            tmp.push_back(top + 1);
            size++;
        }
        int maxstairs = 0;
        for(int i = 0; i < size && bottom < top; i++) {
            int end = tmp[i];
            if(end == bottom) {
                bottom++;
                continue;
            }
            maxstairs = max(maxstairs, end - bottom);
            bottom = ++end;
        }
        return maxstairs;
    }
};

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int size = special.size();
        sort(special.begin(), special.end());
        if(special[size - 1] != top) {
            special.push_back(top + 1);
            size++;
        }
        int maxstairs = 0;
        for(int i = 0; i < size && bottom < top; i++) {
            int end = special[i];
            if(end == bottom) {
                bottom++;
                continue;
            }
            maxstairs = max(maxstairs, end - bottom);
            bottom = ++end;
        }
        return maxstairs;
    }
};

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        int n = special.size();
        int maxstairs = 0;
        for(int i = 0; i < n - 1; i++) {
            maxstairs = max(maxstairs, special[i + 1] - special[i] - 1);
        }
        return maxstairs;
    }
};