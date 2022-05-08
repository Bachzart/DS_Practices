/* prefix sum */
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        vector<long long> pre(size + 1), ave(size + 1);
        for(int i = 0; i < size; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        for(int i = 0; i < size - 1; i++) {
            ave[i] = abs(pre[i + 1] / (i + 1) - (pre[size] - pre[i + 1]) / (size - i - 1));
        }
        ave[size - 1] = pre[size] / size;
        int pos = 0;
        for(int i = 1; i < size; i++) {
            if(ave[i] < ave[pos]) pos = i;
        }
        return pos;
    }
};

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        vector<long long> pre(size + 1);
        for(int i = 0; i < size; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        long long minabsave = LONG_MAX, tmp;
        int pos = -1;
        for(int i = 0; i < size - 1; i++) {
            tmp = abs(pre[i + 1] / (i + 1) - (pre[size] - pre[i + 1]) / (size - i - 1));
            if(tmp < minabsave) {
                minabsave = tmp;
                pos = i;
            }
        }
        tmp = pre[size] / size;
        if(tmp < minabsave) pos = size - 1;
        return pos;
    }
};

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 0;
        long long minabsave = LONG_MAX, tmp, sum = 0, pre = 0;
        for(int i = 0; i < size; i++) {
            sum += nums[i];
        }
        int pos = -1;
        for(int i = 0; i < size - 1; i++) {
            pre += nums[i];
            tmp = abs(pre / (i + 1) - (sum - pre) / (size - i - 1));
            if(tmp < minabsave) {
                minabsave = tmp;
                pos = i;
            }
        }
        tmp = sum / size;
        if(tmp < minabsave) pos = size - 1;
        return pos;
    }
};