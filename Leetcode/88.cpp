/* method 1 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            int tmp = nums2[i], pos = 0;
            while(pos < m && tmp > nums1[pos]) pos++;
            if(pos != m) {
                int index = m;
                while(index > pos) {
                    nums1[index] = nums1[index - 1];
                    index--;
                }
            }
            nums1[pos] = tmp;
            m++;
        }
    }
};

/* method 2 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = 0;
        for(int i = m; i < m + n; i++) {
            nums1[i] = nums2[index++];
        }
        sort(nums1.begin(), nums1.end());
    }
};

/* method 3 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> queue(m + n);
        int pos1 = 0, pos2 = 0, index = 0;
        while(pos1 < m && pos2 < n) {
            if(nums1[pos1] < nums2[pos2]) {
                queue[index] = nums1[pos1];
                pos1++;
            } else {
                queue[index] = nums2[pos2];
                pos2++;
            }
            index++;
        }
        while(pos1 < m) queue[index++] = nums1[pos1++];
        while(pos2 < n) queue[index++] = nums2[pos2++];
        nums1 = queue;
    }
};

/* method 4 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1, index = m + n - 1;
        while(pos1 >= 0 && pos2 >= 0) {
            if(nums1[pos1] > nums2[pos2]) {
                nums1[index] = nums1[pos1];
                pos1--;
            } else {
                nums1[index] = nums2[pos2];
                pos2--;
            }
            index--;
        }
        while(pos1 >= 0) nums1[index--] = nums1[pos1--];
        while(pos2 >= 0) nums1[index--] = nums2[pos2--];
    }
};