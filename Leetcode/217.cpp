class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ht;
        for(auto it: nums) {
            if(ht.find(it) != ht.end()) return true;
            ht.insert(it);
        }
        return false;
    }
};