class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for(int i: nums) {
            counts[i]++;
        }

        int ans = 0;
        if(counts.contains(1)) {
            ans = counts[1] & 1 ? counts[1] : counts[1] - 1;
        }

        counts.erase(1);

        for(auto& [num, _]: counts) {
            int t = 0;
            long long x = num;
            for(; counts.contains(x) && counts[x] > 1; x *= x) {
                t += 2;
            }
            ans = max(ans, t + (counts.contains(x) ? 1 : -1));
        }

        return ans;
    }
};