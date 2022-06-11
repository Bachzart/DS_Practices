class Solution {
public:
    int maxConsecutive(string answerKey, int k, char ch) {
        int n = answerKey.length(), ans = 0;
        for(int left = 0, right = 0, sum = 0; right < n; right++) {
            sum += answerKey[right] != ch;
            while(sum > k) {
                sum -= answerKey[left++] != ch;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxConsecutive(answerKey, k, 'T'), maxConsecutive(answerKey, k, 'F'));
    }
};

/* use lambda function */
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto func = [&](char ch) -> int {
            int n = answerKey.length(), ret = 0;
            for(int left = 0, right = 0, sum = 0; right < n; right++) {
                sum += answerKey[right] != ch;
                while(sum > k) {
                    sum -= answerKey[left++] != ch;
                }
                ret = max(ret, right - left + 1);
            }
            return ret;
        };
        return max(func('T'), func('F'));
    }
};
