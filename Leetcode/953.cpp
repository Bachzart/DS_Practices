class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int seq[26] = {0};
        for(int i = 0; i < order.length(); i++) {
            seq[order[i] - 'a'] = i;
        }
        for(int i = 0; i < words.size() - 1; i++) {
            int minlen = min(words[i].length(), words[i + 1].length()), index = 0;
            bool flag = true;
            while(index < minlen) {
                if(words[i][index] != words[i + 1][index]) {
                    if(seq[words[i][index] - 'a'] > seq[words[i + 1][index] - 'a']) {
                        flag = false;
                    }
                    break;
                } 
                index++;
            }
            if(!flag) return false;
            else if(index == minlen && words[i].length() > words[i + 1].length()) return false;
        }
        return true;
    }
};