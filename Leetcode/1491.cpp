class Solution {
public:
    double average(vector<int>& salary) {
        int size = salary.size(), sum = salary[0], min = salary[0], max = salary[0];
        for(int i = 1; i < size; i++) {
            sum += salary[i];
            if(min > salary[i]) min = salary[i];
            if(max < salary[i]) max = salary[i];
        }
        return (sum - min - max) * 1.0 / (size - 2);
    }
};