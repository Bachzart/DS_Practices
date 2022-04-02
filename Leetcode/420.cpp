class Solution {
public:
    int strongPasswordChecker(string password) {
        int len = password.length();
        bool lower = false, upper = false, digit = false;
        for(auto ch: password) {
            if(islower(ch)) lower = true;
            else if(isupper(ch)) upper = true;
            else if(isdigit(ch)) digit = true;
        }
        int category = lower + upper + digit;
        if(len < 6) {
            return max(6 - len, 3 - category);
        } else if(len <= 20) {
            int replace = 0, cnt = 0;
            char cur = '#';
            for(auto ch: password) {
                if(ch == cur) cnt++;
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            } 
            replace += cnt / 3;
            return max(replace, 3 - category);
        } else {
            int replace = 0, remove = len - 20;
            int rm2 = 0, cnt = 0;
            char cur = '#';
            for(auto ch: password) {
                if(ch == cur) cnt++;
                else {
                    if(remove > 0 && cnt >= 3) {
                        if(cnt % 3 == 0) {
                            remove--;
                            replace--;
                        } else if(cnt % 3 == 1) rm2++;
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if(remove > 0 && cnt >= 3) {
                if(cnt % 3 == 0) {
                    remove--;
                    replace--;
                } else if(cnt % 3 == 1) rm2++;
            }
            replace += cnt / 3;
            int use2 = min({replace, rm2, remove / 2});
            replace -= use2;
            remove -= use2 * 2;
            int use3 = min({replace, remove / 3});
            replace -= use3;
            remove -= use2 * 3;
            return (len - 20) + max(replace, 3 - category);
        }
    }
};