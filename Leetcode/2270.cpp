/* prefixsum */
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int size = nums.size();
        vector<long long> prefixsum(size);
        int ret = 0;
        prefixsum[0] = nums[0];
        for(int i = 1; i < size; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i];
        }
        for(int i = 0; i < size; i++) {
            if(i < size - 1 && prefixsum[i] >= (prefixsum[size - 1] - prefixsum[i])) {
                ret++;
                cout << prefixsum[i] << ' ' << i << endl;
            }
        }
        return ret;
    }
};

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int size = nums.size(), ret = 0;
        long long left = 0, right = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i < size - 1; i++) {
            left += nums[i];
            right -= nums[i];
            if(left >= right) ret++;
        }
        return ret;
    }
};