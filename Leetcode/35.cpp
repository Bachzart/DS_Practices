/* version 1 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (right - left) / 2 + left;
            if(nums[mid] == target) break;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        if(target <= nums[mid]) return mid;
        else return mid + 1;
    }
};

/* version 2, You can also use the lower_bound() function. */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

/* version 3 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right) {
            mid = (right - left) / 2 + left;
            if(nums[mid] == target) break;
            else if(nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        if(target == nums[mid]) return mid;
        else return left;
    }
};