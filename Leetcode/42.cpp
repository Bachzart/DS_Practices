/*
method 1: two pointers
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if(height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};

/*
method 2: monotonic stack

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int n = height.size();
        for(int i = 0; i < n; ++i) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if(st.empty())
                    break;
                int left = st.top();
                int w = i - left - 1;
                int h = min(height[left], height[i]) - height[top];
                ans += w * h;
            }
            st.push(i);
        }
        return ans;
    }
};

*/

/*
method 3: dp

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n, INT_MIN);
        vector<int> rightmax(n, INT_MIN);
        leftmax[0] = height[0], rightmax[n - 1] = height[n - 1];
        for(int i = 1; i < n - 1; ++i)
            leftmax[i] = max(leftmax[i - 1], height[i]);
        for(int i = n - 2; i >= 0; --i) 
            rightmax[i] = max(rightmax[i + 1], height[i]);
        int ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(leftmax[i] > height[i] && height[i] < rightmax[i]) {
                int t = min(leftmax[i], rightmax[i]) - height[i];
                ans += t;
            }
        }
        return ans;
    }
};

*/