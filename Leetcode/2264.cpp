class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> nums;
        int len = num.length();
        for(int i = 0; i < len - 2; i++) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2]) nums.push_back(num.substr(i, 3));
        }
        int size = nums.size();
        sort(nums.begin(), nums.end());
        if(size == 0) return "";
        else return nums[size - 1];
    }
};

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int len = num.length();
        for(int i = 0; i < len - 2; i++) {
            if(num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string tmp = num.substr(i, 3);
                if(tmp > ans) ans = tmp;
            }
        }
        return ans;
    }
};