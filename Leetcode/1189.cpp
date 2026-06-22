class Solution {
public:
    int maxNumberOfBalloons(string text) {
        array<int, 128> counts;
        for(char c: text) {
            counts[c]++;
        }
        return min({counts['a'], counts['b'], counts['l'] / 2, counts['n'], counts['o'] / 2});
    }
};