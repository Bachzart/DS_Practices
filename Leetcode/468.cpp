class Solution {
public:
    string validIPAddress(string queryIP) {
        string valid1 = "IPv4", valid2 = "IPv6", invalid = "Neither";
        if(queryIP.find('.') != string::npos) {
            int last = -1;
            for(int i = 0; i < 4; i++) {
                int cur = (i == 3 ? queryIP.length() : queryIP.find('.', last + 1));
                if(cur == string::npos) return invalid;
                if(cur - last - 1 < 1 || cur - last - 1 > 3) return invalid;
                int addr = 0;
                for(int j = last + 1; j < cur; j++) {
                    if(!isdigit(queryIP[j])) return invalid;
                    addr = addr * 10 + (queryIP[j] - '0');
                }
                if(addr > 255) return invalid;
                if(addr > 0 && queryIP[last + 1] == '0') return invalid;
                if(addr == 0 && cur - last  - 1 > 1) return invalid;
                last = cur;
            }
            return valid1;
        } else {
            int last = -1;
            for(int i = 0; i < 8; i++) {
                int cur = (i == 7 ? queryIP.length() : queryIP.find(':', last + 1));
                if(cur == string::npos) return invalid;
                if(cur - last - 1 < 1 || cur - last - 1 > 4) return invalid;
                for(int j = last + 1; j < cur; j++) {
                    if(!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                        return invalid;
                    }
                }
                last = cur;
            }
            return valid2;
        }
    }
};