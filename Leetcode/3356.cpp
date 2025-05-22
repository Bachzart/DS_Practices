/*
method 1: differential array + two pointers
*/
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> differ(n + 1);
        int k = 0;
        int preSum = 0;
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            preSum += differ[i];
            while(k < queries.size() && preSum < num) {
                differ[queries[k][0]] += queries[k][2];
                differ[queries[k][1] + 1] -= queries[k][2];
                if(queries[k][0] <= i && i <= queries[k][1])
                    preSum += queries[k][2];
                ++k;
            }
            if(preSum < num)
                return -1;
        }
        return k;
    }
};

/*
method 2: differential array + binary search

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        auto check = [&](int k) -> bool {
            vector<int> differ(nums.size() + 1);
            for(int i = 0; i < k; ++i) {
                differ[queries[i][0]] += queries[i][2];
                differ[queries[i][1] + 1] -= queries[i][2];
            }
            int preSum = 0;
            for(int i = 0; i < nums.size(); ++i) {
                preSum += differ[i];
                if(nums[i] > preSum)
                    return false;
            }
            return true;
        };
        int n = queries.size();
        int left = 0, right = n;
        if(!check(right)) 
            return -1;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(check(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

*/