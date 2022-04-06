class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ht;
        vector<int> ret(2);
        for(int i = 0; i < nums.size(); i++) {
            if(ht.find(target - nums[i]) != ht.end()) {
                ret[0] = ht[target - nums[i]], ret[1] = i;
        		break;
        	}
            ht[nums[i]] = i;
        }
        return ret;
    }
};