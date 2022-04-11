/* method 1 */
class Solution {
public:
    bool isHappy(int n) {
        int now;
        set<int> ht;
        while(1) {
            now = 0;
            while(n) {
                now += pow(n % 10, 2);
                n /= 10;
            }
            if(now == 1) return true;
            if(ht.find(now) != ht.end()) break;
            ht.insert(now);
            n = now;
        }
        return false;
    }
};

/* method 2 */
class Solution {
public:
    int getnumber(int n) {
        int ret = 0;
        while(n) {
            int d = n % 10;
            n /= 10;
            ret += d * d;
        }
        return ret;
    }
    bool isHappy(int n) {
        int slow = n, fast = getnumber(n);
        while(fast != 1 && slow != fast) {
            slow = getnumber(slow);
            fast = getnumber(getnumber(fast));
        }
        return fast == 1;
    }
};

/* method 3 */
class Solution {
public:
    unordered_set<int> numbers {4, 16, 37, 58, 89, 145, 42, 20};
    int getnumber(int n) {
        int ret = 0;
        while(n) {
            int d = n % 10;
            n /= 10;
            ret += d * d;
        }
        return ret;
    }
    bool isHappy(int n) {
        int now;
        while(n != 1) {
            now = getnumber(n);
            if(numbers.find(now) != numbers.end()) return false;
            n = now;
        }
        return true;
    }
};