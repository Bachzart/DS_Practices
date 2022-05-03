/* classify the strings and sort, then merge result */
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> charlogs, numlogs;
        int size = logs.size();
        for(int i = 0; i < size; i++) {
            if(isdigit(logs[i][logs[i].find(" ") + 1])) numlogs.push_back(logs[i]);
            else charlogs.push_back(logs[i]);
        }
        sort(charlogs.begin(), charlogs.end(), [&](string a, string b) {
            if(a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) != b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1)) {
                return a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) < b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1);
            } else {
                return a.substr(0, a.find(" ")) < b.substr(0, b.find(" "));
            }
        });
        int index = 0;
        while(index < charlogs.size()) {
            logs[index] = charlogs[index];
            index++;
        }
        for(int i = 0; i < numlogs.size(); i++) {
            logs[index++] = numlogs[i];
        }
        return logs;
    }
};

/* traverse the array from the end to the beginning */
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> charlogs, numlogs;
        int size = logs.size(), index = size - 1;
        for(int i = size - 1; i >= 0; i--) {
            if(isdigit(logs[i][logs[i].find(" ") + 1])) logs[index--] = logs[i];
            else charlogs.push_back(logs[i]);
        }
        sort(charlogs.begin(), charlogs.end(), [&](string a, string b) {
            if(a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) != b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1)) {
                return a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) < b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1);
            } else {
                return a.substr(0, a.find(" ")) < b.substr(0, b.find(" "));
            }
        });
        while(index >= 0) {
            logs[index] = charlogs[index];
            index--;
        }
        return logs;
    }
};

/* use two pointers and sort */
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int size = logs.size(), fast, slow;
        fast = slow = size - 1;
        while(fast >= 0) {
            if(isdigit(logs[fast][logs[fast].find(" ") + 1])) swap(logs[fast--], logs[slow--]);
            else fast--;
        }
        sort(logs.begin(), logs.begin() + slow + 1, [&](string &a, string &b) {
            if(a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) != b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1)) {
                return a.substr(a.find(" ") + 1, a.length() - a.find(" ") - 1) < b.substr(b.find(" ") + 1, b.length() - b.find(" ") - 1);
            } else {
                return a.substr(0, a.find(" ")) < b.substr(0, b.find(" "));
            }
        });
        return logs;
    }
};

/* write compare function */
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [&](const string &a, const string &b) {
            int posa = a.find(" ");
            int posb = b.find(" ");
            bool aisdigit = isdigit(a[posa + 1]);
            bool bisdigit = isdigit(b[posb + 1]);
            if(!aisdigit && !bisdigit) {
                string s1 = a.substr(posa + 1);
                string s2 = b.substr(posb + 1);
                if(s1 != s2) return s1 < s2;
                else return a < b;
            }
            return aisdigit ? false : true;
        });
        return logs;
    }
};