/* method 1: sort */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

/* method 2: two pointers, traverse array from small to large */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size(), min_index = 0, min = nums[0] * nums[0];
        for(int i = 0; i < size; i++) {
            nums[i] = nums[i] * nums[i];
            if(nums[i] < min) {
                min = nums[i];
                min_index = i;
            }
        }
        int left = min_index - 1, right = min_index + 1;
        vector<int> ret;
        ret.push_back(min);
        while(left >= 0 && right <= size - 1) {
            if(nums[left] >= nums[right]) {
                ret.push_back(nums[right]);
                right++;
            } else {
                ret.push_back(nums[left]);
                left--;
            }
        }
        while(left >= 0) {
            ret.push_back(nums[left--]);
        }
        while(right <= size - 1) {
            ret.push_back(nums[right++]);
        }
        return ret;
    }
};

/* method 3: two pointers, traverse array from large to small */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            nums[i] = nums[i] * nums[i];
        }
        vector<int> ret(size);
        int index = size - 1;
        for(int i = 0, j = size - 1; i <= j;) {
            if(nums[i] > nums[j]) ret[index--] = nums[i++];
            else ret[index--] = nums[j--];
        }
        return ret;
    }
};