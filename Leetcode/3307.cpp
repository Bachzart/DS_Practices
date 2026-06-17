/*
Method 2: loop
*/
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int m = bit_width(static_cast<uint64_t>(k) - 1);
        int inc = 0;
        for(int i = m - 1; i >= 0; --i) {
            if(k > (1LL << i)) {
                inc += operations[i];
                k -= 1LL << i;
            }
        }
        return 'a' + inc % 26;
    }
};

/*
Method 1: recursion

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(operations.empty()) {
            return 'a';
        }
        int op = operations.back();
        operations.pop_back();
        int n = operations.size();
        if(n >= 63 || k <= (1LL << n)) {
            return kthCharacter(k, operations);
        }
        char ans = kthCharacter(k - (1LL << n), operations);
        return 'a' + (ans - 'a' + op) % 26;
    }
};
*/