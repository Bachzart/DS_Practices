/* hash + statistic  */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<bool> ht(size);
        vector<vector<string>> ret;
        int amount = 0;
        while(amount < size) {
            vector<int> cnt1(26);
            int index = 0;
            while(index < size && ht[index] == true) index++;
            int len = strs[index].length();
            for(int i = 0; i < len; i++) {
                cnt1[strs[index][i] - 'a']++;
            }
            vector<string> tmp;
            for(int i = 0; i < size; i++) {
                len = strs[i].length();
                vector<int> cnt2(26);
                for(int j = 0; j < len; j++) {
                    cnt2[strs[i][j] - 'a']++;
                }
                if(cnt2 == cnt1) {
                    tmp.push_back(strs[i]);
                    ht[i] = true;
                }
            }
            amount += tmp.size();
            ret.push_back(tmp);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<bool> ht(size);
        vector<vector<string>> ret;
        int amount = 0;
        while(amount < size) {
            vector<int> cnt1(26);
            int index = 0;
            vector<string> tmp;
            while(index < size && ht[index] == true) index++;
            int len = strs[index].length();
            for(int i = 0; i < len; i++) {
                cnt1[strs[index][i] - 'a']++;
            }
            ht[index] = true;
            tmp.push_back(strs[index++]);
            while(index < size) {
                vector<int> cnt2(26);
                int tmplen = strs[index].length();
                if(ht[index] == false && len == tmplen) {
                    for(int i = 0; i < tmplen; i++) {
                        cnt2[strs[index][i] - 'a']++;
                    }
                    if(cnt2 == cnt1) {
                        tmp.push_back(strs[index]);
                        ht[index] = true;
                    }
                }
                index++;
            }
            amount += tmp.size();
            ret.push_back(tmp);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        map<vector<int>, int> indices;
        vector<vector<string>> ret(size);
        int index = 0;
        for(int i = 0; i < size; i++) {
            vector<int> cnt(26);
            int len = strs[i].length();
            for(int j = 0; j < len; j++) {
                cnt[strs[i][j] - 'a']++;
            }
            if(indices.count(cnt)) {
                ret[indices[cnt]].push_back(strs[i]);
            } else {
                ret[index].push_back(strs[i]);
                indices[cnt] = index++;
            }
        }
        vector<vector<string>> ans;
        for(auto &v: ret) {
            if(v.size() != 0) ans.push_back(move(v));
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        map<vector<int>, vector<string>> ht;
        vector<vector<string>> ret;
        for(int i = 0; i < size; i++) {
            vector<int> cnt(26);
            int len = strs[i].length();
            for(int j = 0; j < len; j++) {
                cnt[strs[i][j] - 'a']++;
            }
            ht[cnt].push_back(strs[i]);
        }
        for(auto &[v1, v2]: ht) {
            ret.push_back(v2);
        }
        return ret;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for(string &str: strs) {
            array<int, 26> counts{};
            int len = str.length();
            for(int i = 0; i < len; i++) {
                counts[str[i] - 'a']++;
            }
            mp[counts].push_back(str);
        }
        vector<vector<string>> ret;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
};

/* hash + sort */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        unordered_map<string, vector<string>> mp;
        for(string &s: strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ret;
        for(auto &[s, v]: mp) {
            ret.push_back(v);
        }
        return ret;
    }
};