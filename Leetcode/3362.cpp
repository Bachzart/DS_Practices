class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        priority_queue<int> heap;
        int n = nums.size();
        vector<int> differ(n + 1);
        int preSum = 0;
        for(int i = 0, j = 0; i < n; ++i) {
            preSum += differ[i];
            while(j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            while(preSum < nums[i] && !heap.empty() && heap.top() >= i) {
                preSum += 1;
                differ[heap.top() + 1] -= 1;
                heap.pop();
            }
            if(preSum < nums[i])
                return -1;
        }
        return heap.size();
    }
};