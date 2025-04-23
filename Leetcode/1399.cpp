/*
method 1: hash with int map
*/
class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[40] = {0};
        int maxSize = 0;
        for(int i = 1; i <= n; ++i) {
            int num = i;
            int sum = 0;
            while(num) {
                sum += num % 10;
                num /= 10;
            }
            ++cnt[sum];
            maxSize = max(maxSize, cnt[sum]);
        }
        int ans = 0;
        for(int i: cnt) {
            if(i == maxSize)
                ++ans;
        }
        return ans;
    }
};

/*
method 2: hash with STL map

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> cnt;
        int maxSize = 0;
        for(int i = 1; i <= n; ++i) {
            int num = i;
            int sum = 0;
            while(num) {
                sum += num % 10;
                num /= 10;
            }
            ++cnt[sum];
            maxSize = max(maxSize, cnt[sum]);
        }
        int ans = 0;
        for(auto &[_, t]: cnt) {
            if(t == maxSize)
                ++ans;
        }
        return ans;
    }
};

*/