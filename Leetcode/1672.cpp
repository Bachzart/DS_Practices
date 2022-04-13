class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = -1, sum;
        for(int i = 0; i < accounts.size(); i++) {
            sum = 0;
            for(int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[j];
            }
            if(max < sum) max = sum;
        }
        return max;
    }
};

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxwealth = -1, sum;
        for(int i = 0; i < accounts.size(); i++) {
            maxwealth = max(maxwealth, accumulate(accounts[i].begin(), accounts[i].end(), 0));
        }
        return maxwealth;
    }
};