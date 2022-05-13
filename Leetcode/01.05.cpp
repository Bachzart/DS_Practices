class Solution {
public:
    bool oneEditAway(string first, string second) {
        int flen = first.length(), slen = second.length(), cnt = 0;
        if(flen - slen == 1) return oneinsert(first, second);
        else if(slen - flen == 1) return oneinsert(second, first);
        else if(slen == flen) {
            bool finddifferent = false;
            for(int i = 0; i < flen; i++) {
                if(first[i] != second[i]) {
                    if(!finddifferent) finddifferent = true;
                    else return false;
                }
            }
            return true;
        } else return false;
    }
    bool oneinsert(string longer, string shorter) {
        int len1 = longer.length(), len2 = shorter.length();
        int index1 = 0, index2 = 0;
        while(index1 < len1 && index2 < len2) {
            cout << index1 << ' ' << index2 << endl;
            if(longer[index1] == shorter[index2]) index2++;
            index1++;
            if(index1 - index2 > 1) return false;
        }
        return true;
    }
};