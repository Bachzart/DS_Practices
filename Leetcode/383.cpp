class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.length() < ransomNote.length()) return false;
        int times[26] = {0};
        for(auto ch: magazine) {
            times[ch - 'a']++;
        }
        for(auto ch: ransomNote) {
            times[ch - 'a']--;
            if(times[ch - 'a'] < 0) return false;
        }
        return true;
    }
};