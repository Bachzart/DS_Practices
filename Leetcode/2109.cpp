/*
method 1: violent solutions
*/
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        int idx = 0;
        for(int i: spaces) {
            while(idx < i) 
                ret += s[idx++];
            ret += ' ';
        }
        while(idx < s.length())
            ret += s[idx++];
        return ret;
    }
};


/*
method 2: violent solutions

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int cnt = 0;
        for(int i: spaces) {
            s.insert(i + cnt, " ");
            ++cnt;
        }
        return s;
    }
};
*/