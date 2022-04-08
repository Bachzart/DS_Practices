/* method 1 */
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(; low <= high; low++) {
            if(low % 2) count++;
        }
        return count;
    }
};

/* method 2 */
class Solution {
public:
    int countOdds(int low, int high) {
        if(low % 2 && high % 2) return (high - low) / 2 + 1;
        else return (high - low) / 2 + high % 2 + low % 2;
    }
};

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + (high % 2 || low % 2);
    }
};

/* method 3 */
class Solution {
public:
    int countOdds(int low, int high) {
        return ((high + 1) >> 1) - (low >> 1);
    }
};