/* sort + binary search, ceil */
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++) {
            long long tmp = (success % spells[i] == 0 ? success / spells[i] : success / spells[i] + 1);
            ans[i] = potions.end() - lower_bound(potions.begin(), potions.end(), tmp);
        }
        return ans;
    }
};

/* sort + binary search, floor */
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        for(int i = 0; i < n; i++) {
            ans[i] = potions.end() - upper_bound(potions.begin(), potions.end(), (success - 1) / spells[i]);
        }
        return ans;
    }
};