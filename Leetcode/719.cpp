/* violent solution, TLE. */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        multiset<int> disofpair;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = abs(nums[j] - nums[i]);
                disofpair.insert(tmp);
            }
        }
        auto it = disofpair.begin();
        while(k > 1 && it != disofpair.end()) {
            it++;
            k--;
        }
        return *it;
    }
};

/* violent solutions with using vector, also TLE. */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> disofpair;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int tmp = abs(nums[j] - nums[i]);
                disofpair.push_back(tmp);
            }
        }
        sort(disofpair.begin(), disofpair.end());
        return disofpair[k - 1];
    }
};

/* sort + binary search + binary search, AC. */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), n = nums.size();
        while(left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                int j = lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin();
                cnt += i - j;
            }
            if(cnt >= k) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

/* sort + binary search + silding window, AC. */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), n = nums.size();
        while(left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for(int l = 0, r = 0; r < n; r++) {
                while(nums[r] - nums[l] > mid) l++;
                cnt += r - l;
            }
            if(cnt >= k) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};