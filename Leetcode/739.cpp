/* method 1：violent solution */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ret(size);
        for(int i = 0; i < size; i++) {
            int index = i + 1;
            while(index < size && temperatures[index] <= temperatures[i]) index++;
            if(index != size) ret[i] = index - i;
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ret(size), indices(101, INT_MAX);
        for(int i = size - 1; i >= 0; i--) {
            int warmerindex = INT_MAX;
            for(int tem = temperatures[i] + 1; tem <= 100; tem++) {
                warmerindex = min(warmerindex, indices[tem]);
            }
            if(warmerindex == INT_MAX) ret[i] = 0;
            else ret[i] = warmerindex - i;
            indices[temperatures[i]] = i;
        }
        return ret;
    }
};

/* method 2: monotonic stack */
// from end to start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
        vector<int> ret(size);
        for(int i = size - 1; i >= 0; i--) {
            int tmp = temperatures[i];
            while(!st.empty() && temperatures[st.top()] <= tmp) st.pop();
            ret[i] = st.empty() ? 0 : st.top() - i;
            st.push(i); 
        }
        return ret;
    }
};

// from start to end
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int size = temperatures.size();
        vector<int> ret(size);
        for(int i = 0; i < size; i++) {
            int tem = temperatures[i];
            while(!st.empty() && tem > temperatures[st.top()]) {
                int previousindex = st.top();
                ret[previousindex] = i - previousindex;
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};