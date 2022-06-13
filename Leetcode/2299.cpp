/* simulate */
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        string ht = "!@#$%^&*()-+";
        int n = password.size();
        if(n < 8) return false;
        bool lower = false, upper = false, num = false, spec = false, consective = false;
        for(int i = 0; i < n; i++) {
            if(isupper(password[i])) upper = true;
            if(islower(password[i])) lower = true;
            if(isdigit(password[i])) num = true;
            if(ht.find(password[i]) != string::npos) spec = true;
            if(i != 0 && password[i] == password[i - 1]) consective = true;
        }
        return lower && upper && num && spec && !consective;
    }
};

/* use bit replace bool variables */
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();
        if(n < 8) return false;
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(i > 0 && password[i] == password[i - 1]) return false;
            if(isupper(password[i])) flag |= 1;
            else if(islower(password[i])) flag |= 2;
            else if(isdigit(password[i])) flag |= 4;
            else flag |= 8;
        }
        return flag == 15;
    }
};