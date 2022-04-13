/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
/* method 1 */
class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {

    }
    
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        st2.push(x);
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty()) return false;
        int front = st1.top();
        st1.pop();
        return front;
    }
    
    int peek() {
        if(st1.empty()) return false;
        else return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

/* method 2 */
class MyQueue {
public:
    int front;
    stack<int> st1, st2;
    MyQueue() {

    }
    
    void push(int x) {
        if(st1.empty()) front = x;
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int tmp = st2.top();
        st2.pop();
        return tmp;
    }
    
    int peek() {
        if(!st2.empty()) return st2.top();
        return front;
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
};