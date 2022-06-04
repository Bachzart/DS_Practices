class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ht;
        for(auto &str: emails) {
            string tmp = "";
            int i, atpos = str.find('@'), len = str.length();
            for(i = 0; i < atpos; i++) {
                if(str[i] == '.') continue;
                else if(str[i] == '+') {
                    i++;
                    while(i < atpos && str[i] != '+') i++;
                    i--;
                } else tmp.push_back(str[i]);
            }
            tmp += str.substr(atpos, len - atpos);
            if(!ht.count(tmp)) ht.insert(tmp);
        }
        return ht.size();
    }
};

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ht;
        for(auto &str: emails) {
            string tmp = "";
            int atpos = str.find('@'), len = str.length();
            for(int i = 0; i < atpos; i++) {
                if(str[i] == '+') break;
                else if(str[i] == '.') continue;
                else tmp.push_back(str[i]);
            }
            tmp += str.substr(atpos, len - atpos);
            if(!ht.count(tmp)) ht.insert(tmp);
        }
        return ht.size();
    }
};