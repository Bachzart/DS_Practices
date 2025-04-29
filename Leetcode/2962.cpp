/*
sliding window 1
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> indice{-1};
        for(int i = 0; i < n; ++i) 
            if(nums[i] == maxNum)
                indice.push_back(i);
        int left = 1, right = k;
        long long ans = 0;
        while(right < indice.size()) {
            ans += 1LL * (indice[left] - indice[left - 1]) * (n - indice[right]);
            ++left, ++right;
        }
        return ans;
    }
};

/*
// sliding window 2

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxNumCnt = 0;
        int n = nums.size();
        long long ans = 0;
        for(int left = 0, right = 0; right < n; ++right) {
            maxNumCnt += nums[right] == maxNum;
            while(maxNumCnt == k) {
                maxNumCnt -= nums[left++] == maxNum;
            }
            ans += left;
        }
        return ans;
    }
};
*/

/*
// sliding window 1:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());
        int maxNumCnt = 0;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            while(j < n && maxNumCnt < k) {
                if(nums[j++] == maxNum)
                    ++maxNumCnt;
            }
            if(maxNumCnt == k)
                ans += n - j + 1;
            if(nums[i] == maxNum)
                --maxNumCnt;
        }
        return ans;
    }
};

*/