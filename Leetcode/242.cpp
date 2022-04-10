/* method 1 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> count1(26), count2(26);
        for(auto ch: s) {
            count1[ch - 'a']++;
        }
        for(auto ch: t) {
            count2[ch - 'a']++;
        }
        if(count1 == count2) return true;
        else return false;
    }
};

/* method 2 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};