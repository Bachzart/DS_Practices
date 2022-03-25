/* method 1 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ret(nums.size());
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) ret[index++] = nums[i];
        }
        nums = ret;
    }
};

/* method 2 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0, second = 1, size = nums.size();
        while(first < size) {
            if(nums[first] == 0) {
                while(second < size && nums[second] == 0) second++;
                if(second < size) {
                    swap(nums[first], nums[second]);
                    first++, second++;
                } else break;
            } else {
                first++;
                if(second <= first) second++;
            }
        }
    }
};

/* method 3 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, size = nums.size();
        while(right < size) {
          if(nums[right]) {
            swap(nums[left], nums[right]);
            left++;
          }
          right++;
        }
    }
};