class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int len1 = num1.length(), len2 = num2.length(), maxlen, carry = 0;
        maxlen = max(len1, len2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < maxlen; i++) {
            int sum = carry;
            sum += i < len1 ? num1[i] - '0' : 0;
            sum += i < len2 ? num2[i] - '0' : 0;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            ans.push_back(sum + '0');
        }
        if(carry) ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int len1 = num1.length(), len2 = num2.length(), carry = 0;
        for(int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--) {
            int sum = carry;
            sum += i >= 0 ? num1[i] - '0' : 0;
            sum += j >= 0 ? num2[j] - '0' : 0;
            if(sum >= 10) {
                carry = 1;
                sum -= 10;
            } else carry = 0;
            ans.push_back(sum + '0');
        }
        if(carry) ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};