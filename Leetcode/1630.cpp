/* method 1: violent solution */
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int size = nums.size(), rangesize = l.size();
        vector<bool> ret(rangesize);
        for(int i = 0; i < rangesize; i++) {
            int left = l[i], right = r[i];
            vector<int> tmp;
            while(left <= right) tmp.push_back(nums[left++]);
            sort(tmp.begin(), tmp.end());
            int diff = tmp[1] - tmp[0];
            bool flag = true;
            for(int j = 1; j < tmp.size() - 1; j++) {
                if(diff != tmp[j + 1] - tmp[j]) {
                    ret[i] = false;
                    flag = false;
                    break;
                }
            }
            if(flag) ret[i] = true;
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int rangesize = l.size();
        vector<bool> ret(rangesize);
        for(int i = 0; i < rangesize; i++) {
            int left = l[i], right = r[i];
            int min1 = INT_MAX, min2 = INT_MAX;
            for(int j = left; j <= right; j++) {
                if(nums[j] < min1 && nums[j] < min2) {
                    min2 = min1;
                    min1 = nums[j];
                } else if(nums[j] >= min1 && nums[j] < min2) {
                    min2 = nums[j];
                }
            }
            int size = right - left + 1;
            if(size <= 2) {
                ret[i] = true;
                continue;
            }
            int d = min2 - min1;
            bool flag = true;
            vector<bool> visited(size, false);
            for(int j = left; j <= right; j++) {
                int tmp = nums[j] - min1;
                if((d == 0 && tmp != 0) || (d != 0 && (tmp % d != 0 || tmp / d >= size || visited[tmp / d]))) {
                    flag = false;
                    break;
                }
                if(d != 0) visited[tmp / d] = true;
            }
            ret[i] = flag;
        }
        return ret;
    }
};