/* method 1: violent solutions can not accpet. */
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size(), maxvalue = INT_MIN;
        if(size == 1) return 0;
        for(int i = 0; i < size; i++) {
            int value = 0, index = size - i, cnt = 0;
            for(int j = index; j < size; j++) {
                value += (cnt++ * nums[j]);
            }
            for(int j = 0; j < index; j++) {
                value += (cnt++ * nums[j]);
            }
            if(value > maxvalue) maxvalue = value;
        }
        return maxvalue;
    }
};

/* method 2: dp */
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size = nums.size(), maxvalue, sum = 0, pre = 0;
        if(size == 1) return 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
            pre += nums[i] * i;
        }
        maxvalue = pre;
        for(int i = 1; i < size; i++) {
            pre = pre + sum - size * nums[size - i];
            maxvalue = max(maxvalue, pre);
        }
        return maxvalue;
    }
};