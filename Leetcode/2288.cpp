class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int len = sentence.length();
        string ret = "";
        for(int i = 0; i < len; i++) {
            if(sentence[i] != '$') ret.push_back(sentence[i]);
            else {
                ret.push_back(sentence[i]);
                if(i > 0 && sentence[i - 1] != ' ') continue;
                i++;
                if(i == len) break;
                if(!isdigit(sentence[i])) {
                    ret.push_back(sentence[i]);
                    continue;
                }
                double tmp = 0;
                bool flag = true;
                int pos = i;
                while(i < len && sentence[i] != ' ') {
                    if(!isdigit(sentence[i]) && sentence[i] != ' ') {
                        flag = false;
                        break;
                    }
                    tmp = tmp * 10 + sentence[i] - '0';
                    i++;
                } 
                if(flag) {
                   tmp = tmp * (1 - discount / 100.0) + 0.005;
                    string t = to_string(tmp);
                    int j = 0;
                    while(j < t.length() && t[j] != '.') {
                        ret.push_back(t[j]);
                        j++;
                    }
                    ret.push_back(t[j]);
                    ret.push_back(t[j + 1]);
                    ret.push_back(t[j + 2]);
                    if(i != len) {
                        ret.push_back(sentence[i]);
                    }
                } else {
                    ret += sentence.substr(pos, i - pos + 1);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int len = sentence.length();
        string ret = "";
        for(int i = 0; i < len; i++) {
            if(sentence[i] != '$') ret.push_back(sentence[i]);
            else {
                ret.push_back(sentence[i]);
                if(i > 0 && sentence[i - 1] != ' ') continue;
                i++;
                if(i == len) break;
                if(!isdigit(sentence[i])) {
                    ret.push_back(sentence[i]);
                    continue;
                }
                double tmp = 0;
                bool flag = true;
                int pos = i;
                while(i < len && sentence[i] != ' ') {
                    if(!isdigit(sentence[i]) && sentence[i] != ' ') {
                        flag = false;
                        break;
                    }
                    tmp = tmp * 10 + sentence[i] - '0';
                    i++;
                } 
                if(flag) {
                   tmp = tmp * (1 - discount / 100.0) + 0.005;
                    string t = to_string(tmp);
                    int j = 0;
                    while(j < t.length() && t[j] != '.') {
                        ret.push_back(t[j]);
                        j++;
                    }
                    for(int k = j; k < j + 3; k++) {
                        ret.push_back(t[k]);
                    }
                    if(i != len) ret.push_back(sentence[i]);
                } else {
                    ret += sentence.substr(pos, i - pos + 1);
                }
            }
        }
        return ret;
    }
};