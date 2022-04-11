class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length()) return false;
        vector<int> index;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) index.push_back(i);
            if(index.size() == 2) break;
        }
        if(index.size() == 0) return true;
        else if(index.size() == 1) return false;
        swap(s2[index[0]], s2[index[1]]);
        return s1 == s2;
    }
};