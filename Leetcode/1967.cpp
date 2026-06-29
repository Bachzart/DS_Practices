class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(const string& s: patterns) {
            // if(word.find(s) != string::npos)
            if(word.contains(s))
                ++ans;
        }
        return ans;
    }
};