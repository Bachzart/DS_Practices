/*
method 1: bit operation
*/
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0)
                continue;
            int x = nums[i];
            int cur = i;
            while(nums[cur] != i) {
                int next = nums[cur];
                nums[cur] = ~nums[next];
                cur = next;
            }
            nums[cur] = ~x;
        }
        for(int i = 0; i < n; ++i)
            nums[i] = ~nums[i];
        return nums;
    }
};

/*
method 2: simulation v1

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) 
            nums[i] += (nums[nums[i]] % 1000) * 1000;
        for(int i = 0; i < n; ++i)
            nums[i] /= 1000;
        return nums;
    }
};
*/

/*
method 3: simulation v2

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i: nums) {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

*/