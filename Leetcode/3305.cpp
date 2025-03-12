/*
method 1: sliding window
*/
class Solution {
public:
    int countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        function<long long(int)> count = [&](int m) -> long long {
            int n = word.length(), conconants = 0;
            long long res = 0;
            map<char, int> occur;
            for(int i = 0, j = 0; i < n; ++i) {
                while(j < n && (conconants < m || occur.size() < vowels.size())) {
                    if(vowels.count(word[j]))
                        ++occur[word[j]];
                    else 
                        ++conconants;
                    ++j;
                }
                if(conconants >= m && occur.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if(vowels.count(word[i])) {
                    --occur[word[i]];
                    if(occur[word[i]] == 0)
                        occur.erase(word[i]);
                } else {
                    --conconants;
                }

            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};

/*
method 2: violent solution

class Solution {
public:
    int countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int len = word.length();
        long long res = 0;
        for(int i = 0; i < len; ++i) {
            set<char> occur;
            int consonants = 0;
            for(int j = i; j < len; ++j) {
                if(vowels.count(word[j])) 
                    occur.insert(word[j]);
                else
                    ++consonants;
                if(occur.size() == vowels.size() && consonants == k)
                    ++res;
            }
        }
        return res;
    }
};
*/