class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            /* You can also write this way to avoid overflows.
            mid = (right - left) / 2 + left;
            */
            mid = (left + right) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else if(nums[mid] == target) return mid;
            
        }
        return -1;
    }
};