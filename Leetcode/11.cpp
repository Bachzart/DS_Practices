class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = INT_MIN;
        while(left < right) {
            int area = (right - left) * min(height[left], height[right]);
            cout << area << endl;
            ans = max(ans, area);
            if(height[left] < height[right]) 
                ++left;
            else 
                --right;
        }
        return ans;
    }
};