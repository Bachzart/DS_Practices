class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        int n = messages.size(), mmax = INT_MIN;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            bool flag = true;
            for(char &ch: messages[i]) {
                if(flag && ch != ' ') {
                    cnt++;
                    flag = false;
                } else if(ch == ' ') flag = true;
            }
            mp[senders[i]] += cnt;
            mmax = max(mmax, mp[senders[i]]);
        }
        string ret = "";
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            if(it->second == mmax) {
                ret = it->first;
                break;
            }
        }
        return ret;
    }
};

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> mp;
        int n = messages.size(), mmax = INT_MIN;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            bool flag = true;
            for(char &ch: messages[i]) {
                if(ch == ' ') cnt++;
            }
            mp[senders[i]] += ++cnt;
            mmax = max(mmax, mp[senders[i]]);
        }
        string ret = "";
        for(auto it = mp.rbegin(); it != mp.rend(); it++) {
            if(it->second == mmax) {
                ret = it->first;
                break;
            }
        }
        return ret;
    }
};