/*
Method 2: Counting Sort
*/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt(n + 1);
        for(int x: arr) {
            cnt[min(x, n)]++;
        }

        int ans = 0;
        for(int x = 1; x <= n; ++x) {
            ans = min(ans + cnt[x], x);
        }
        return ans;
    }
};

/*
Method 1: Greedy + Sort

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < n; ++i) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }
        return arr.back();
    }
};

*/