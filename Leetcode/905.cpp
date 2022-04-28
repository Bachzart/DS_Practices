/* method 1 */
class Solution {
public:
    unordered_map<int, int> tmp;
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            tmp[nums[i]] = nums[i] % 2;
        }
        sort(nums.begin(), nums.end(), [this](int a, int b) { return tmp[a] < tmp[b]});
        return nums;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int front = 0, rear = 0, size = nums.size();
        while(front < size) {
            if(nums[front] % 2 == 0) {
                swap(nums[front], nums[rear]);
                rear++;
            }
            front++;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, size = nums.size(), right = size - 1;
        while(left < right) {
            while(left < right and nums[left] % 2 == 0) left++;
            while(right > left and nums[right] % 2 != 0) right--;
            if(left< right) swap(nums[left], nums[right]);
        }
        return nums;
    }
};