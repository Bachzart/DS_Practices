/* use a auxiliary array */
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), index = 0;
        vector<int> tmp(n);
        for(int i = 0; i < n; i++) {
            if(arr[index] == 0) tmp[i++] = arr[index];            
            if(i < n) tmp[i] = arr[index++];
            else break;
        }
        arr = tmp;
    }
};