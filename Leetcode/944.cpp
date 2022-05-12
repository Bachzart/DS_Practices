class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int size = strs.size(), len = strs[0].length(), cnt = 0;
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < size - 1; j++) {
                if(strs[j + 1][i] < strs[j][i]) {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};