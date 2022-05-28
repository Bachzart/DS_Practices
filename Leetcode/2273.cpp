class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int size = words.size();
        vector<string> ret;
        int i = 0;
        while(i < size) {
            string s1 = words[i];
            ret.push_back(words[i]);
            sort(s1.begin(), s1.end());
            int j = i + 1;
            while(j < size) {
                string s2 = words[j];
                sort(s2.begin(), s2.end());
                if(s2 != s1) break;
                j++;
            }
            i = j;
        }
        return ret;
    }
};