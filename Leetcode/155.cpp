/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
/* method 1 */
class MinStack {
    int stk[30010];
    int tp, minimumofstk;
public:
    MinStack() {
        tp = -1;
        minimumofstk = INT_MAX;
    }
    
    void push(int val) {
        stk[++tp] = val;
        if(val < minimumofstk) minimumofstk = val;
    }
    
    void pop() {
        int tmp = stk[tp--];
        if(tp == -1) minimumofstk = INT_MAX;
        else if(tmp == minimumofstk) {
            minimumofstk = stk[tp];
            for(int i = 0; i < tp; i++) {
                if(stk[i] < minimumofstk) minimumofstk = stk[i];
            }
        }
    }
    
    int top() {
        return stk[tp];
    }
    
    int getMin() {
        return minimumofstk;
    }
};

/* method 2 */
class MinStack {
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) {
        stk.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};