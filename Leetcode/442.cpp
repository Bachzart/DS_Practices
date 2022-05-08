/* method 1: hash, but space complexity is O(n), time complexity is O(n). */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        unordered_map<int, int> ht;
        for(int &i: nums) {
            ht[i]++;
            if(ht[i] > 1) ret.push_back(i);
        }
        return ret;
    }
};

/* method 2: violent solution, but time complexity is O(n^2), space complexity is O(1). */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(size == 1) return ret;
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(nums[j] == nums[i]) ret.push_back(nums[i]);
            }
        }
        return ret;
    }
};

/* method 3: swap the elements */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(size == 1) return ret;
        for(int i = 0; i < size; i++) {
            while(nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < size; i++) {
            if(nums[i] - 1 != i) ret.push_back(nums[i]);
        }
        return ret;
    }
};

/* method 4: change the numbers positive or negative to represent the numbers appear or not. */
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int size = nums.size();
        if(size == 1) return ret;
        for(int i = 0; i < size; i++) {
            int x = abs(nums[i]);
            if(nums[x - 1] > 0) {
                nums[x - 1] = -nums[x - 1];
            } else {
                ret.push_back(x);
            }
        }
        return ret;
    }
};