/*
Method 1: violent solution
Note: No in-place and stable partition algorithm.
*/
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int cnt = 0;
        for(int i: nums) {
            if(i < pivot) {
                ans.push_back(i);
            } else if(i == pivot) {
                ++cnt;
            }
        }
        while(cnt--) {
            ans.push_back(pivot);
        }
        for(int i: nums) {
            if(i > pivot) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};