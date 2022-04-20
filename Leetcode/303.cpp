/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/* method 1 */
class NumArray {
public:
    int numbers[10005] = {0};
    NumArray(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            numbers[i] = nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        while(left <= right) {
            sum += numbers[left++];
        }
        return sum;
    }
};

/* method 2 */
class NumArray {
public:
    int numbers[10005] = {0};
    NumArray(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            numbers[i + 1] = nums[i] + numbers[i];
        }
    }
    
    int sumRange(int left, int right) {
        return numbers[right + 1] - numbers[left];
    }
};