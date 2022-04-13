class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, count = 0;
        for(int i = 0; i < s.length(); i++) {
            count += widths[s[i] - 'a'];
            if(count > 100) {
                count = widths[s[i] - 'a'];
                lines++;
            } else if(count == 100) {
                if(i == s.length() - 1) break;
                count = 0;
                lines++;
            }
        }
        return {lines, count};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1, count = 0;
        for(int i = 0; i < s.length(); i++) {
            count += widths[s[i] - 'a'];
            if(count > 100) {
                count = widths[s[i] - 'a'];
                lines++;
            }
        }
        return {lines, count};
    }
};