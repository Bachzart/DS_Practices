class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int lastspaceindex = INT_MAX, lastcharindex = INT_MAX;
        for(int i = len - 1; i >= 0; i--) {
            if(isalpha(s[i]) && lastcharindex == INT_MAX) lastcharindex = i;
            if(s[i] == ' ' && lastcharindex != INT_MAX) {
                lastspaceindex = i;
                break;
            }
        }
        if(lastspaceindex == INT_MAX) return lastcharindex + 1;
        else return lastcharindex - lastspaceindex;
    }
};

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int spaceindex, lastcharindex = len - 1;
        for(int i = len - 1; i >= 0; i--) {
            if(isalpha(s[i])) {
                lastcharindex = i;
                break;
            }
        }
        spaceindex = lastcharindex - 1;
        while(spaceindex >= 0) {
            if(s[spaceindex] == ' ') break;
            spaceindex--;
        }
        if(spaceindex == -1) return lastcharindex + 1;
        else return lastcharindex - spaceindex;
    }
};