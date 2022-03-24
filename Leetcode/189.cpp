/* method 1: use queue, but cost many memory */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), tmp;
        vector<int> ret;
        queue<int> q;
        k %= size;
        for(int i = 0; i < size; i++) {
            q.push(nums[i]);
        }
        for(int i = 0; i < size - k; i++) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        while(!q.epmty()) {
            ret.push_back(q.front());
            q.pop();
        }
        nums = ret;
    }
};

/* method 2: use vector, also cost many memory */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), tmp;
        vector<int> ret;
        k %= size;
        for(int i = size - k; i < size; i++) {
            ret.push_back(nums[i]);
        }
        for(int i = 0; i < size - k; i++) {
            ret.push_back(nums[i]);
        }
        nums = ret;
    }
};

/* method 3: use reverse function */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), tmp;
        k %= size;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

/* method 4: exchange value directly */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size(), tmp;
        k %= size;
        /* version 1 */
        int count = gcd(size, k);
        for(int start = 0; start < count; start++) {
            int cur = start;
            int prev = nums[start];
            do{
                int next = (cur + k) % size;
                swap(nums[next], prev);
                cur = next;
            } while(start != cur);
        }
        /* version 2 
        int count = 0;
        for(int start = 0; count < n; start++) {
            int cur = start;
            int prev = nums[start];
            do{
                int next = (cur + k) % size;
                swap(nums[next], prev);
                cur = next;
                count++;
            } while(start != cur);
        }
        */
    }
};