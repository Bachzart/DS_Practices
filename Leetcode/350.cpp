/* method 1 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int m = nums1.size(), n = nums2.size();
        for(int i = 0; i < m; i++) {
            int tmp = nums1[i];
            for(int j = 0; j < n; j++) {
                if(tmp == nums2[j]) {
                    nums2[j] = -1;
                    ret.push_back(tmp);
                    break;
                }
            }
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int ht1[1005] = {0}, ht2[1005] = {0};
        for(int i = 0; i < nums1.size(); i++) {
            ht1[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            ht2[nums2[i]]++;
        }
        for(int i = 0; i < 1001; i++) {
            if(ht1[i] && ht2[i]) {
                int tmp = ht1[i] > ht2[i] ? ht2[i] : ht1[i];
                for(int j = 0; j < tmp; j++) {
                    ret.push_back(i);
                }
            }
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        int ht[1005] = {0};
        for(int i = 0; i < nums1.size(); i++) {
            ht[nums1[i]]++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            if(ht[nums2[i]]) {
                ret.push_back(nums2[i]);
                ht[nums2[i]]--;
            }
        }
        return ret;
    }
};