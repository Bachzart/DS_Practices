/* linear search */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(auto ch: letters) {
            if(ch > target) return ch;
        }
        return letters[0];
    }
};

/* binary search */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return target < letters.back() ? *upper_bound(letters.begin(), letters.end(), target) : letters[0];
    }
};