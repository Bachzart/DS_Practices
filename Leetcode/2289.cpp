/* violent solution, TLE. */
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int cnt = 0;
        while(true) {
            int n = nums.size();
            vector<int> tmp;
            bool flag = true;
            tmp.push_back(nums[0]);
            for(int i = 1; i < n; i++) {
                if(nums[i] < nums[i - 1]) flag = false;
                else tmp.push_back(nums[i]);
            }
            if(!flag) cnt++;
            else break;
            nums = tmp;
        }
        return cnt;
    }
};

/* monotonic stack */
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int ans = INT_MIN;
        stack<pair<int, int>> st;
        for(int i: nums) {
            int maxt = 0;
            while(!st.empty() && st.top().first <= i) {
                maxt = max(maxt, st.top().second);
                st.pop();
            }
            maxt = st.empty() == true ? 0 : maxt + 1;
            st.emplace(i, maxt);
            ans = max(ans, maxt);
        }
        return ans;
    }
};