class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto& str: words) {
            int weight = 0;
            for(char& c: str) {
                weight += weights[c - 'a'];
            }
            weight %= 26;
            ans.push_back('z' - weight);
        }
        return ans;
    }
};