class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int pos = size - 2;
        while(pos >= 0 && nums[pos] >= nums[pos + 1]) pos--;
        if(pos == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int nextpos = size - 1;
            while(nextpos >= 0 && nums[nextpos] <= nums[pos]) nextpos--;
            swap(nums[pos], nums[nextpos]);
            reverse(nums.begin() + pos + 1, nums.end());
        }
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};