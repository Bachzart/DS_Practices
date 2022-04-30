/* method 1 */
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return true;
        int p1 = 0, p2 = 1;
        while(p1 < size && p2 < size && nums[p1] == nums[p2]) p1++, p2++;
        if(p2 == size) return true;
        if(nums[p1] >= nums[p2]) {
            for(int i = 1; i < size - 1; i++) {
                if(nums[i] < nums[i + 1]) return false;
            }
        } else {
            for(int i = 1; i < size - 1; i++) {
                if(nums[i] > nums[i + 1]) return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true, dec = true;
        int size = nums.size();
        for(int i = 0; i < size - 1; i++) {
            if(nums[i] > nums[i + 1]) inc = false;
            if(nums[i] < nums[i + 1]) dec = false;
        }
        return inc || dec;
    }
};

/* method 2 */
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
    }
};