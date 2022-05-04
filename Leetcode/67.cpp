class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int len1 = a.length(), len2 = b.length();
        int p1 = 0, p2 = 0, carry = 0;
        while(p1 < len1 && p2 < len2) {
            int tmp = a[p1++] + b[p2++] + carry - 2 * '0';
            if(tmp == 0) {
                ans.push_back('0');
                carry = 0;
            } else if(tmp == 1) {
                ans.push_back('1');
                carry = 0;
            } else if(tmp == 2) {
                ans.push_back('0');
                carry = 1;
            } else {
                ans.push_back('1');
                carry = 1;
            }
        }
        while(p1 < len1) {
            int tmp = carry + a[p1++] - '0';
            if(tmp == 0) {
                ans.push_back('0');
                carry = 0;
            } else if(tmp == 1) {
                ans.push_back('1');
                carry = 0;
            } else {
                ans.push_back('0');
                carry = 1;
            }
        }
        while(p2 < len2) {
            int tmp = carry + b[p2++] - '0';
            if(tmp == 0) {
                ans.push_back('0');
                carry = 0;
            } else if(tmp == 1) {
                ans.push_back('1');
                carry = 0;
            } else {
                ans.push_back('0');
                carry = 1;
            }
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
    void addremains(string &s, int &pos, string &ans, int &carry) {
        while(pos < s.length()) {
            int tmp = carry + s[pos++] - '0';
            if(tmp == 0) {
                ans.push_back('0');
                carry = 0;
            } else if(tmp == 1) {
                ans.push_back('1');
                carry = 0;
            } else {
                ans.push_back('0');
                carry = 1;
            }
        }
    }
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int len1 = a.length(), len2 = b.length();
        int p1 = 0, p2 = 0, carry = 0;
        while(p1 < len1 && p2 < len2) {
            int tmp = a[p1++] + b[p2++] + carry - 2 * '0';
            if(tmp == 0) {
                ans.push_back('0');
                carry = 0;
            } else if(tmp == 1) {
                ans.push_back('1');
                carry = 0;
            } else if(tmp == 2) {
                ans.push_back('0');
                carry = 1;
            } else {
                ans.push_back('1');
                carry = 1;
            }
        }
        if(p1 != len1) addremains(a, p1, ans, carry);
        if(p2 != len2) addremains(b, p2, ans, carry);
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int len1 = a.length(), len2 = b.length();
        int maxlen = max(len1, len2), carry = 0;
        for(int i = 0; i < maxlen; i++) {
            carry += i < len1 ? (a[i] == '1') : 0;
            carry += i < len2 ? (b[i] == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};