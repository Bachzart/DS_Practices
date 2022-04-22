class Solution {
public:
    bool havevowel(char c) {
        bool ret = false;
        switch(c) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': ret = true; break;
            default: break; 
        }
        return ret;
    }
    string toGoatLatin(string sentence) {
        int len = sentence.length();
        string ret;
        int pos = 0, cnt = 0;
        while(pos < len) {
            if(havevowel(sentence[pos])) {
                ret += sentence[pos++];
                while(sentence[pos] != ' ' && pos < len) ret += sentence[pos++];
            } else {
                char tmp = sentence[pos++];
                while(sentence[pos] != ' ' && pos < len) ret += sentence[pos++];
                ret += tmp;
            }
            ret += "ma";
            cnt++;
            for(int i = 0; i < cnt; i++) ret += "a";
            if(pos != len) ret += sentence[pos++];
        }
        return ret;
    }
};

class Solution {
public:
    string toGoatLatin(string sentence) {
        set<char> ht = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        int len = sentence.length();
        string ret;
        int pos = 0, cnt = 0;
        while(pos < len) {
            if(ht.count(sentence[pos])) {
                ret += sentence[pos++];
                while(sentence[pos] != ' ' && pos < len) ret += sentence[pos++];
            } else {
                char tmp = sentence[pos++];
                while(sentence[pos] != ' ' && pos < len) ret += sentence[pos++];
                ret += tmp;
            }
            ret += "ma";
            ret += string(++cnt, 'a');
            if(pos != len) ret += sentence[pos++];
        }
        return ret;
    }
};