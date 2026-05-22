class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size(), ans = -1;
        if(sz == 1 && nums[0] == target) {
            ans = 0;
        }

        int l = 0, r = sz - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            }
            if(nums[0] <= nums[mid]) {
                if(nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(nums[mid] < target && target <= nums[sz - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return ans;
    }
};