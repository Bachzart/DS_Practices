class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1, size = nums.size();
        if(size == 0) return size;
        for(; fast < size; fast++) {
            if(nums[fast] != nums[fast - 1]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow++;
    }
};