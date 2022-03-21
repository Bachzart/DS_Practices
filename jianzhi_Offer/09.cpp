class CQueue {
    stack<int> st1, st2;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        if(st1.empty()) {
            st1.push(value);
        } else {
            while(!st1.empty()) {
                int tmp = st1.top();
                st2.push(tmp);
                st1.pop();
            }
            st2.push(value);
            while(!st2.empty()) {
                int tmp = st2.top();
                st1.push(tmp);
                st2.pop();
            }
        }
    }
    
    int deleteHead() {
        if(st1.empty()) return -1;
        else {
            int tmp = st1.top();
            st1.pop();
            return tmp;
        }
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */