/* violent solution */
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> ht;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            string tmp = words[i];
            for(char &c: tmp) {
                c |= 32;
            }
            ht[tmp].push_back(i);
        }
        for(char &c: word1) {
            c |= 32;
        }
        for(char &c: word2) {
            c |= 32;
        }
        int mindis = INT_MAX;
        for(int i: ht[word1]) {
            for(int j: ht[word2]) {
                mindis = min(mindis, abs(i - j));
            }
        }
        return mindis;
    }
};

/* It's not necessary to distinguish uppercase and lowercase. */
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> ht;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            ht[words[i]].push_back(i);
        }
        int mindis = INT_MAX;
        for(int i: ht[word1]) {
            for(int j: ht[word2]) {
                mindis = min(mindis, abs(i - j));
            }
        }
        return mindis;
    }
};

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int mindis = INT_MAX;
        int index1 = -1, index2= -1;
        for(int i = 0; i < size; i++) {
            if(words[i] == word1) index1 = i;
            else if(words[i] == word2) index2 = i;
            if(index1 > 0 && index2 > 0) {
                mindis = min(mindis, abs(index1 - index2));
            }
        }
        return mindis;
    }
};