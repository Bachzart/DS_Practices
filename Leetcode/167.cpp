/* method 1: violent solution, will cause time limit exceeded. */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        int size = numbers.size();
        for(int i = 0; i < numbers.size(); i++) {
            for(int j = i + 1; j < numbers.size(); j++) {
                if(numbers[j] + numbers[i] == target) {
                    ret.push_back(i + 1);
                    ret.push_back(j + 1);
                }
            }
        }
        return ret;
    }
};

/* method 2: use hash map */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret(2);
        map<int, int> hash;
        int size = numbers.size();
        hash[numbers[0]] = 0;
        for(int i = 1; i < size; i++) {
            if(hash.find(target - numbers[i]) != hash.end()) {
                ret[0] = hash[target - numbers[i]] + 1;
                ret[1] = i + 1;
            }
            hash[numbers[i]] = i;
        }
        return ret;
    }
};

/* method 3: use binary search */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            int left = i + 1, right = numbers.size() - 1;
            while(left <= right) {
                int mid = (right + left) / 2;
                if(numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if(numbers[mid] > target - numbers[i]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return {-1, -1};
    }
};

/* method 4: use two pointers */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum < target) left++;
            else if(sum > target) right++;
            else return {left + 1, right + 1};
        }
        return {-1, -1};
    }
};