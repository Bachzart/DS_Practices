/*
method 1: prefix sum + hash
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        ht[0] = 1;
        int cnt = 0, pre = 0;
        for(int &i: nums) {
            pre += i;
            if(ht.find(pre - k) != ht.end()) {
                cnt += ht[pre - k];
            }
            ht[pre]++;
        }
        return cnt;

    }
};

/*
method 2: prefix sum

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preSum(n + 1);
        for(int i = 0; i < n; ++i)
            preSum[i + 1] = preSum[i] + nums[i];

        int ret = 0;
        for(int i = n; i > 0; --i) {
            for(int j = i - 1; j >= 0; --j) {
                if(preSum[i] - preSum[j] == k)
                    ret++;
            }
        }
        return ret;
    }
};
*/

/*
method 3: violent solution

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = 0;
        for(int i = 0; i < n; ++i) {
            int sum = 0;
            for(int j = i; j < n; ++j) {
                sum += nums[j];
                if(sum == k) {
                    ret++;
                }
            }
        }
        return ret;
    }
};
*/