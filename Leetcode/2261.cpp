class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>, bool> ht;
        int ret = 0, size = nums.size();
        for(int i = 0; i < size; i++) {
            vector<int> tmp;
            int cnt = 0;
            for(int j = i; j < size; j++) {
                tmp.push_back(nums[j]);
                if(nums[j] % p == 0) cnt++;
                if(cnt > k) break;
                else {
                    if(!ht.count(tmp)) {
                        ht[tmp] = true;
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> arrs;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            string s;
            int cnt = 0;
            for(int j = i; j < size; j++) {
                if(nums[j] % p == 0) cnt++;
                if(cnt > k) break;
                s.append(to_string(nums[j]));
                s.push_back('#');
                arrs.insert(s);
            }
        }
        return arrs.size();
    }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        map<vector<int>, bool> ht;
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            vector<int> tmp;
            int cnt = 0;
            for(int j = i; j < size; j++) {
                tmp.push_back(nums[j]);
                if(nums[j] % p == 0) cnt++;
                if(cnt > k) break;
                ht[tmp] = true;
            }
        }
        return ht.size();
    }
};