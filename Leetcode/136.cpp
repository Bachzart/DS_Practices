/* method 1 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ht;
        for(int i = 0; i < nums.size(); i++) {
            ht[nums[i]]++;
        }
        int ret = 0;
        for(auto it: ht) {
            if(it.second == 1) {
                ret = it.first;
                break;
            }
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto i: nums) {
            ret ^= i;
        }
        return ret;
    }
};