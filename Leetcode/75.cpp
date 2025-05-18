/*
method: two pointer
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p2 = n - 1;
        for(int i = 0; i <= p2; ++i) {
            while(i <= p2 && nums[i] == 2) 
                swap(nums[i], nums[p2--]);
            if(nums[i] == 0)
                swap(nums[i], nums[p0++]);
        }
    }
};

/*
method: two pointer

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 1) 
                swap(nums[i], nums[p1++]);
            else if(nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if(p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};
*/

/*
method: two pass

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] == 0) 
                swap(nums[ptr++], nums[i]);
        }
        for(int i = ptr; i < n; ++i) {
            if(nums[i] == 1) 
                swap(nums[ptr++], nums[i]);
        }
    }
};
*/

/*
method: counting sort / hash, not a smart way
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0};
        for(int i: nums)
            ++cnt[i];
        int idx = 0;
        for(int i = 0; i < 3; ++i) {
            while(cnt[i]--) 
                nums[idx++] = i;
        }
    }
};
*/