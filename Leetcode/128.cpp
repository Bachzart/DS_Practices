/*
method 1: hash
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ht(nums.begin(), nums.end());
        int ans = 0;
        for(const int &i: ht) {
            if(ht.count(i - 1)) 
                continue;
            else {
                int n = i + 1, cnt = 1;
                while(ht.count(n)) {
                    ++n, ++cnt;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};


/* method 2: sort + set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return size;
        set<int> ht;
        for(int &i: nums) {
            ht.insert(i);
        }
        int ans = 0;
        auto it = ht.begin();
        int preNum = *it, cnt;
        while(it != ht.end()) {
            auto it2 = ++it;
            cnt = 1;
            while(it2 != ht.end()) {
                if(*it2 != preNum + 1)
                    break;
                else {
                    preNum = *it2++;
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
            it = it2;
            preNum = *it;
        }
        return ans;
    }
};

*/