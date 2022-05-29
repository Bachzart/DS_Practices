class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for(char c: s) {
            if(c == letter) cnt++;
        }
        cout << cnt << endl;
        return cnt * 100 / s.length();
    }
};