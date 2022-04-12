/* method 1 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        ret.resize(nums1.size());
        for(int i = 0;i < nums1.size(); i++) {
            bool flag1 = false, flag2 = false;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums2[j] == nums1[i]) flag1 = true;
                if(flag1 && nums2[j] > nums1[i]) {
                    ret[i] = nums2[j];
                    flag2 = true;
                    break;
                }
            }
            if(!flag2) ret[i] = -1;
        }
        return ret;
    }
};

/* method 2 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> ht;
        for(int i = nums2.size() - 1; i >= 0; i--) {
            int num = nums2[i];
            while(!st.empty() && num >= st.top()) st.pop();
            ht[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> ret;
        for(int i = 0; i < nums1.size(); i++) {
            ret.push_back(ht[nums1[i]]);
        }
        return ret;
    }
};