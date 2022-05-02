/* method 1 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size(), i = 0;
        reverse(digits.begin(), digits.end());
        int carry = 1;
        while(i < size) {
            digits[i] += carry;
            if(digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            } else carry = 0;
            i++;
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size(), i = 0;
        if(digits[size - 1] + 1 < 10) {
            digits[size - 1] += 1;
            return digits;
        }
        reverse(digits.begin(), digits.end());
        int carry = 1;
        while(i < size) {
            digits[i] += carry;
            if(digits[i] >= 10) {
                digits[i] -= 10;
                carry = 1;
            } else carry = 0;
            i++;
        }
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int i = size - 1;
        while(i >= 0) {
            digits[i]++;
            if(digits[i] == 10) digits[i] = 0;
            else break;
            i--;
        }
        if(digits[0] == 0) {
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};