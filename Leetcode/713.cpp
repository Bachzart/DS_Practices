/* method 1: violent solution */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size(), cnt = 0;
        for(int i = 0; i < size; i++) {
            int product = nums[i];
            if(product < k) cnt++;
            for(int j = i + 1; j < size; j++) {
                product *= nums[j];
                if(product < k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};

/* method 2: binary search + prefix sum + math */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int size = nums.size();
        vector<double> logprefix(size + 1);
        for(int i = 0; i < size; i++) {
            logprefix[i + 1] = logprefix[i] + log(nums[i]);
        }
        double logk = log(k);
        int cnt = 0;
        for(int i = 0; i < size; i++) {
            int l = upper_bound(logprefix.begin(), logprefix.begin() + i + 1, logprefix[i + 1] - log(k) + 1e-10) - logprefix.begin();
            cnt += i + 1 - l;
        }
        return cnt;
    }
};

/* method 3: sliding window */
// move left pointer
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size(), cnt = 0;
        int product = 1, i = 0;
        for(int j = 0; j < size; j++) {
            product *= nums[j];
            while(i <= j && product >= k) {
                product /= nums[i];
                i++;
            }
            cnt += j - i + 1;
        }
        return cnt;
    }
};

// move right pointer
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size(), cnt = 0;
        int product = 1, left, right;
        left = right = 0;
        while(left <= right && right < size) {
            while(right < size && product * nums[right] < k) {
                cnt += right - left + 1;
                product *= nums[right++];
            }
            if(left == right) right++;
            else product /= nums[left];
            left++;
        }
        return cnt;
    }
};