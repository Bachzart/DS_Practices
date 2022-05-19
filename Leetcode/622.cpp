/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        maxsize = k + 1;
        data.resize(maxsize);
        front = rear = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        rear = (rear + 1) % maxsize;
        data[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % maxsize;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return data[(front + 1) % maxsize];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        else return data[rear];
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % maxsize == front;
    }
private:
    vector<int> data;
    int front, rear, maxsize;
};