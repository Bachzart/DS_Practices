class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        if(len != goal.length()) return false;
        string tmp;
        for(int i = 0; i < len; i++) {
            tmp = s.substr(i, len - i);
            tmp += s.substr(0, i);
            if(tmp == goal) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string s, string goal) {
        return s.length() == goal.length() && (s + s).find(goal) != string::npos;
    }
};