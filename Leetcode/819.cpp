class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(int i = 0; i < paragraph.length(); i++) {
            if(isupper(paragraph[i])) paragraph[i] &= 32;
        }
        int i = 0;
        unordered_map<string, int> ht;
        while(i < paragraph.length()) {
            if(islower(paragraph[i])) {
                string tmp;
                for(int j = i; j < paragraph.length(); j++) {
                    if(islower(paragraph[j])) tmp += paragraph[j];
                    else {
                        i = j;
                        break;
                    }
                }
                if(!count(banned.begin(), banned.end(), tmp)) ht[tmp]++;
            }
            i++;
        }
        unordered_map<string, int>::iterator it = ht.begin();
        int max = it->second;
        string ret = it->first;
        it++;
        for(; it != ht.end(); it++) {
            if(max < it->second) {
                max = it->second;
                ret = it->first;
            }
        }
        return ret;
    }
};