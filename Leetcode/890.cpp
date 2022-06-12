/* use two hashtables */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(string &word: words) {
            unordered_map<char, char> word2pat, pat2word;
            int len = word.size();
            bool flag = true;
            for(int i = 0; i < len; i++) {
                if(word2pat.count(word[i]) && word2pat[word[i]] != pattern[i]) flag = false;
                if(pat2word.count(pattern[i]) && pat2word[pattern[i]] != word[i]) flag = false;
                word2pat[word[i]] = pattern[i];
                pat2word[pattern[i]] = word[i];
            }
            if(flag) ans.push_back(word);
        }
        return ans;
    }
};

/* use one hashtable */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto match = [](string &word, string &pattern) -> bool {
            unordered_map<char, char> mp;
            int n = word.size();
            for(int i = 0; i < n; i++) {
                if(!mp.count(word[i])) mp[word[i]] = pattern[i];
                else if(mp[word[i]] != pattern[i]) return false;
            }
            return true;
        };
        for(string &word: words) {
            if(match(word, pattern) && match(pattern, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};

/* use a simplified hashtable */
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        auto match = [](string &word, string &pattern) -> bool {
            int mp[26] = {0};
            int n = word.size();
            for(int i = 0; i < n; i++) {
                if(!mp[word[i] - 'a']) mp[word[i] - 'a'] = pattern[i];
                else if(mp[word[i] - 'a'] != pattern[i]) return false;
            }
            return true;
        };
        for(string &word: words) {
            if(match(word, pattern) && match(pattern, word)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};