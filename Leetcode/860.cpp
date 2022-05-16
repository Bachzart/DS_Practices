class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five, ten;
        five = ten = 0;
        int size = bills.size();
        for(int i = 0; i < size; i++) {
            if(bills[i] == 10) {
                five--;
                ten++;
                if(five < 0) return false;
            } else if(bills[i] == 20) {
                if(ten == 0) five -= 3;
                else {
                    ten--;
                    five--;
                }
                if(ten < 0 || five < 0) return false;
            } else five++;
        }
        return true;
    }
};