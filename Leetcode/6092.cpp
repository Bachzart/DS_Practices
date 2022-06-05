/* hash + simulate */
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size(), m = operations.size();
        unordered_map<int, int> indices;
        for(int i = 0; i < n; i++) {
            indices[nums[i]] = i;
        }
        for(int i = 0; i < m; i++) {
            int x = operations[i][0], y = operations[i][1];
            int index = indices[x];
            nums[index] = y;
            indices[y] = index;
            indices.erase(x);
        }
        return nums;
    }
};

/* hash + simulate + reverse thinking */
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mp;
        int m = operations.size();
        for(int i = m - 1; i >= 0; i--) {
            if(!mp.count(operations[i][1])) mp[operations[i][0]] = operations[i][1];
            else mp[operations[i][0]] = mp[operations[i][1]];
        }
        for(int &i: nums) {
            if(mp.count(i)) i = mp[i];
        }
        return nums;
    }
};