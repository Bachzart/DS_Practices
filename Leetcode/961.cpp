/* hash */
class Solution {
public:
    int ht[10005] = {0};
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size(), i;
        for(i = 0; i < size; i++) {
            ht[nums[i]]++;
            if(ht[nums[i]] == 2) break;
        }
        return nums[i];
    }
};

/* math */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        for(int step = 1; step <= 3; step++) {
            for(int i = 0; i + step < size; i++) {
                if(nums[i] == nums[i + step]) return nums[i];
            }
        }
        return -1;
    }
};

/* random selection */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size();
        mt19937 gen{random_device{}()};
        uniform_int_distribution<int> dis(0, size - 1);
        while(true) {
            int x = dis(gen), y = dis(gen);
            if(x != y && nums[x] == nums[y]) return nums[x];
        }
    }
};