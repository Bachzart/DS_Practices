class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> ht;
        for(int i: arr1) {
            while(i > 0) {
                ht.insert(i);
                i /= 10;
            }
        }

        int ans = 0;
        for(int i: arr2) {
            while(i > 0) {
                if(ht.count(i)) 
                    ans = max(ans, i);
                i /= 10;
            }
        }

        return ans == 0 ? ans : to_string(ans).length();
    }
};