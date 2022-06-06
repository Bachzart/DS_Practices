class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int cnt = 0;
        int left = 0, right;
        while(left < n) {
            int right = left;
            while(right < n && nums[right] - nums[left] <= k) right++;
            cnt++;
            left = right;
        }
        return cnt;
    }
};

class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), cnt = 0;
        for(int i = 0, j = 0; j < n; j++) {
            if(nums[j] - nums[i] > k) {
                cnt++;
                i = j;
            }
        }
        return cnt + 1;
    }
};