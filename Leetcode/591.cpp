class Solution {
public:
    bool isValid(string code) {
        int len = code.length();
        stack<string> tags;
        int i = 0;
        while(i < len) {
            if(code[i] == '<') {
                if(i == len - 1) return false;
                if(code[i + 1] == '/') {
                    int j = code.find('>', i);
                    if(j == string::npos) return false;
                    string tagname = code.substr(i + 2, j - (i + 2));
                    if(tags.empty() || tags.top() != tagname) return false;
                    tags.pop();
                    i = j + 1;
                    if(tags.empty() && i != len) return false;
                } else if(code[i + 1] == '!') {
                    if(tags.empty()) return false;
                    string cdata = code.substr(i + 2, 7);
                    if(cdata != "[CDATA[") return false;
                    int j = code.find("]]>", i);
                    if(j == string::npos) return false;
                    i = j + 1;
                } else {
                    int j = code.find('>', i);
                    if(j == string::npos) return false;
                    string tagname = code.substr(i + 1, j - (i + 1));
                    if(tagname.length() < 1 || tagname.length() > 9) return false;
                    if(!all_of(tagname.begin(), tagname.end(), [](unsigned char c) { return isupper(c); })) {
                        return false;
                    }
                    tags.push(move(tagname));
                    i = j + 1;
                }
            } else {
                if(tags.empty()) return false;
                i++;
            } 
        }
        return tags.empty();
    }
};