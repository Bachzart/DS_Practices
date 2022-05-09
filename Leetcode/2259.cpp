class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> indices;
        int len = number.length();
        for(int i = 0; i < len; i++) {
            if(number[i] == digit) indices.push_back(i);
        }
        if(indices.size() == 1) {
            number.erase(number.begin() + indices[0]);
            return number;
        } else {
            string max = number;
            max.erase(max.begin() + indices[0]);
            for(int i = 1; i < indices.size(); i++) {
                string t = number;
                t.erase(t.begin() + indices[i]);
                if(max < t) max = t;
            }
            return max;
        }
    }
};

/* greedy */
class Solution {
public:
    string removeDigit(string number, char digit) {
        int len = number.length(), pos = -1;
        for(int i = 0; i < len; i++) {
            if(number[i] == digit) {
                pos = i;
                if(i + 1 < len && number[i] < number[i + 1]) break;
            }
        }
        number.erase(number.begin() + pos);
        return number;
    }
};