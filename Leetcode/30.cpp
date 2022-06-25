/* hash + sliding window */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_set<string> ht;
        for(auto str: words) {
            ht.insert(str);
        }
        int l = words[0].length();
        int left = 0, right = 0, len = s.length();
        multiset<string> window;
        vector<int> ans;
        while(left < len) {
            window.clear();
            unordered_set<string> htmp = ht;
            while(right < len) {
                string t = s.substr(right, l);
                right += l;
                if(htmp.count(t)) {
                    window.insert(t);
                    htmp.erase(t);
                } else break;
                if(window.size() == words.size()) break;
            }
            if(window.size() == words.size()) ans.push_back(left);
            left = right;
        }
        return ans;
    }
};
