/* method 1 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string ans = "0";
        int len1 = num1.length(), len2 = num2.length();
        for(int i = len2 - 1; i >= 0; i--) {
            string curr;
            int add = 0;
            for(int j = len2 - 1; j > i; j--) {
                curr.push_back(0);
            }
            int y = num2.at(i) - '0';
            for(int j = len1 - 1; j >= 0; j--) {
                int x = num1.at(j) - '0';
                int product = x * y + add;
                curr.push_back(product % 10);
                add = product / 10;
            }
            while(add != 0) {
                curr.push_back(add % 10);
                add /= 10;
            }
            reverse(curr.begin(), curr.end());
            for(auto &c: curr) {
                c += '0';
            }
            ans = addStrings(ans, curr);
        }
        return ans;
    }
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

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        string ans = "0";
        int len1 = num1.length(), len2 = num2.length();
        for(int i = len2 - 1; i >= 0; i--) {
            string tmp;
            int number = num2[i] - '0', carry = 0;
            for(int j = len2 - 1; j > i; j--) {
                tmp.push_back('0');
            }
            for(int j = len1 - 1; j >= 0; j--) {
                int res = number * (num1[j] - '0') + carry;
                if(res > 9) {
                    carry = res / 10;
                    res %= 10;
                } else carry = 0;
                tmp.push_back(res + '0');
            }
            while(carry) {
                tmp.push_back(carry % 10 + '0');
                carry /= 10;
            }
            reverse(tmp.begin(), tmp.end());
            ans = addStrings(ans, tmp);
        }
        return ans;
    }
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

/* method 2 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int len1 = num1.length(), len2 = num2.length();
        vector<int> ansarr(len1 + len2);
        for(int i = len1 - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for(int j = len2 - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                ansarr[i + j + 1] += x * y;
            }
        }
        for(int i = len1 + len2 - 1; i > 0; i--) {
            ansarr[i - 1] += ansarr[i] / 10;
            ansarr[i] %= 10;
        }
        int index = ansarr[0] == 0 ? 1 : 0;
        string ans;
        while(index < len1 + len2) {
            ans.push_back(ansarr[index++] + '0');
        }
        return ans;
    }
};