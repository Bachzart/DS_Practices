/* method 1: use a array to copy */
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> ret;
        for(int i = s.size() - 1; i >= 0; i--) {
            ret.push_back(s[i]);
        }
        s = ret;
    }
};

/* method 2: just exchange the elements */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for(int i = 0; i < size / 2; i++) {
            char tmp = s[size - i - 1];
            s[size - i - 1] = s[i];
            s[i] = tmp;
        }
    }
};

/* also can write like this */
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

