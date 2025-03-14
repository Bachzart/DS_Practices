class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        auto count = [&](int m) -> long long {
            int n = word.length(), conconants = 0;
            long long res = 0;
            map<char, int> ht;
            for(int i = 0, j = 0; i < n; ++i) {
                while(j < n && (conconants < m || ht.size() < vowels.size())) {
                    if(vowels.count(word[j]))
                        ++ht[word[j]];
                    else
                        ++conconants;
                    ++j;
                }
                if(conconants >= m && ht.size() == vowels.size()) {
                    res += n - j + 1;
                }
                if(vowels.count(word[i])) {
                    --ht[word[i]];
                    if(ht[word[i]] == 0)
                        ht.erase(word[i]);
                } else {
                    --conconants;
                }
            }
            return res;
        };
        return count(k) - count(k + 1);
    }
};