class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> knum, ans;
        while(k) {
            knum.push_back(k % 10);
            k /= 10;
        }
        reverse(num.begin(), num.end());
        int carry = 0, size1 = num.size(), size2 = knum.size();
        int maxsize = max(size1, size2);
        for(int i = 0; i < maxsize; i++) {
            carry += i < size1 ? num[i] : 0;
            carry += i < size2 ? knum[i] : 0;
            ans.push_back(carry % 10);
            carry /= 10;
        }
        if(carry) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int size = num.size();
        for(int i = size - 1; i >= 0; i--) {
            int sum = num[i] + k % 10;
            k /= 10;
            if(sum >= 10) {
                k++;
                sum -= 10;
            }
            ans.push_back(sum);
        }
        while(k) {
            ans.push_back(k % 10);
            k /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int size = num.size();
        vector<int> ans;
        for(int i = size - 1; i >= 0 || k > 0; i--, k /= 10) {
            if(i >= 0) k += num[i];
            ans.push_back(k % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};