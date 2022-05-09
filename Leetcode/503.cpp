/* violent solution */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> ret(size);
    	for(int i = 0; i < size; i++) {
    		int left = 0, right = i + 1;
            while(right < size && nums[right] <= nums[i]) right++;
            while(left < i && nums[left] <= nums[i]) left++;
            if(right != size) ret[i] = nums[right];
            else if(left != i) ret[i] = nums[left];
            else ret[i] = -1;
    	}
    	return ret;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> ret(size);
    	for(int i = 0; i < size; i++) {
    		int pre = 0, rear = i + 1;
    		bool flag = false;
            while(rear < size) {
            	if(nums[rear] > nums[i]) {
            		ret[i] = nums[rear];
            		flag = true;
            		break;
            	}
            	rear++;
            }
            if(flag) continue;
            else {
            	while(pre < i) {
            		if(nums[pre] > nums[i]) {
            			ret[i] = nums[pre];
            			break;
            		}
            		pre++;
            	}
            	if(pre == i) ret[i] = -1;
            }
    	}
    	return ret;
    }
};

/* monotonic stack */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> ret(size, -1);
    	stack<int> st;
    	for(int i = 0; i < size * 2 - 1; i++) {
    		while(!st.empty() && nums[st.top()] < nums[i % size]) {
    			ret[st.top()] = nums[i % size];
    			st.pop();
    		}
    		st.push(i % size);
    	}
    	return ret;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	int size = nums.size();
    	vector<int> ret(size, -1);
    	stack<int> st;
    	for(int i = 0; i < size; i++) {
    		while(!st.empty() && nums[st.top()] < nums[i]) {
    			ret[st.top()] = nums[i];
    			st.pop();
    		}
    		st.push(i % size);
    	}
    	for(int i = 0; i < size; i++) {
    		while(!st.empty() && nums[st.top()] < nums[i]) {
    			ret[st.top()] = nums[i];
    			st.pop();
    		}
    	}
    	return ret;
    }
};