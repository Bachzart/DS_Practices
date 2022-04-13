/* method 1 */
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), sum = 0;
        for(int step = 1; step <= size; step += 2) {
            for(int i = 0; i < size; i++) {
                if(i + step <= size) {
                    for(int j = i; j < i + step; j++) {
                        sum += arr[j];
                    }
                } else break;
            }
        }
        return sum;
    }
};

/* method 2 */
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), sum = 0;
        vector<int> prefixnum(size + 1);
        for(int i = 0; i < size; i++) {
            prefixnum[i + 1] = prefixnum[i] + arr[i];
        }
        for(int i = 0; i < size; i++) {
            for(int step = 1; step + i <= size; step += 2) {
                int tmp = i + step - 1;
                sum += prefixnum[tmp + 1] - prefixnum[i];
            }
        }
        return sum;
    }
};

/* method 3 */
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int size = arr.size(), sum = 0;
        for(int i = 0; i < size; i++) {
            int leftcount = i, rightcount = size - i - 1;
            int leftodd = (leftcount + 1) / 2, rightodd = (rightcount + 1) / 2;
            int lefteven = leftcount / 2 + 1, righteven = rightcount / 2 + 1;
            sum += arr[i] * (leftodd * rightodd + lefteven * righteven);
        }
        return sum;
    }
};