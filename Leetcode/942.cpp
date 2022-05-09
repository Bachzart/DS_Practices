class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.length();
        vector<int> perm(len + 1);
        int left = 0, right = len, index = 0;
        while(index < len) {
            if(s[index] == 'I') perm[index] = left++;
            else perm[index] = right--;
            index++;
        }
        perm[index] = left;
        return perm;
    }
};