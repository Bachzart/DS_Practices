class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), min_diff = INT_MAX;
        for(int i = 1; i < n; i++) {
            int tmp = arr[i] - arr[i - 1];
            if(min_diff > tmp) min_diff = tmp; 
        }
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++) {
            int tmp = arr[i] - arr[i - 1];
            if(min_diff == tmp) ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), min_diff = INT_MAX;
        vector<vector<int>> ans;
        for(int i = 1; i < n; i++) {
            int tmp = arr[i] - arr[i - 1];
            if(min_diff > tmp) {
                min_diff = tmp; 
                ans = {{arr[i - 1], arr[i]}};
            } else if(min_diff == tmp) ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};