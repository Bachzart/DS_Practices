/* traversal s */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        int index = 0;
        string tmp;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] != ' ') tmp.push_back(s[i]);
            if(s[i] == ' ' || i == s.length() - 1) {
                if(!char2word.count(pattern[index]) && !word2char.count(tmp)) {
                    char2word[pattern[index]] = tmp;
                    word2char[tmp] = pattern[index];
                } else if(char2word.count(pattern[index]) && word2char.count(tmp)) {
                    if(!(pattern[index] == word2char[tmp] && char2word[pattern[index]] == tmp)) return false;
                } else return false;
                tmp = "";
                ++index;
            } 
        }
        if(index != pattern.length()) return false;
        else return true;
    }
};

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        int index = 0;
        string tmp;
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] != ' ') tmp.push_back(s[i]);
            if(s[i] == ' ' || i == s.length() - 1) {
                if(word2char.count(tmp) && word2char[tmp] != pattern[index]) return false;
                if(char2word.count(pattern[index]) && char2word[pattern[index]] != tmp) return false;
                word2char[tmp] = pattern[index];
                char2word[pattern[index]] = tmp;
                tmp = "";
                ++index;
            } 
        }
        if(index != pattern.length()) return false;
        else return true;
    }
};

/* traversal pattern */
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> char2word;
        unordered_map<string, char> word2char;
        int m = s.length();
        int i = 0;
        for(char ch: pattern) {
            if(i >= m) return false;
            int j = i;
            while(j < m && s[j] != ' ') j++;
            const string &tmp = str.substr(i, j - i);
            if(word2char.count(tmp) && word2char[tmp] != ch) return false;
            if(char2word.count(ch) && char2word[ch] != tmp) return false;
            word2char[tmp] = ch;
            char2word[ch] = tmp;
            i = j + 1;
        }
        return i >= m;
    }
};