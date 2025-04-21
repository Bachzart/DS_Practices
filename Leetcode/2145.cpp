/*
method 1: presum + math
*/
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_s = 0, max_s = 0, d = 0;
        for(int i: differences) {
            d += i;
            min_s = min(min_s, d);
            max_s = max(max_s, d);
        }
        return max(upper - max_s - lower + min_s + 1, 0LL);
    }
};

/*
lower <= a + di <= upper

lower - di <= a <= upper - di



*/


/*
method 2: two pointers

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        int left = lower, right = upper;
        while(left <= upper) {
            int t = left;
            int idx;
            for(idx = 0; idx < n; ++idx) {
                t += differences[idx];
                if(lower > t || t > upper)
                    break;
            }
            if(idx == n)
                break;
            ++left;
        }
        while(right >= lower) {
            int t = right;
            int idx;
            for(idx = 0; idx < n; ++idx) {
                t += differences[idx];
                if(lower > t || t > upper)
                    break;
            }
            if(idx == n)
                break;
            --right;
        }
        if(left > right)
            return 0;
        else
            return right - left + 1; 
    }
};
*/