class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(int i = 0; i < operations.size(); i++) {
            gem[operations[i][1]] += gem[operations[i][0]] / 2;
            gem[operations[i][0]] -= gem[operations[i][0]] / 2;
        }
        int max = gem[0], min = gem[0];
        for(int i = 0; i < gem.size(); i++) {
            if(max < gem[i]) max = gem[i];
            if(min > gem[i]) min = gem[i];
        }
        return max - min;
    }
};

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(int i = 0; i < operations.size(); i++) {
            gem[operations[i][1]] += gem[operations[i][0]] / 2;
            gem[operations[i][0]] -= gem[operations[i][0]] / 2;
        }
        return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
    }
};