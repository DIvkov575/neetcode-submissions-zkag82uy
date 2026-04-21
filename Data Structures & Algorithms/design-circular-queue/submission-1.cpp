class MyCircularQueue {
    vector<int> buf;
    int fp{};
    int bp{};
    int size{};

    int cap;

public:
    MyCircularQueue(int k): cap(k), buf(k, 0) {  }
    
    bool enQueue(int value) {
        if (isFull()) { return false; }
        buf[fp] = value;
        fp = (fp + 1) % cap;
        size += 1;

        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) { return false; }
        bp = (bp + 1) % cap;
        size -= 1;

        return true; 
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return buf[bp];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return buf[(fp - 1 + cap) % cap];
    }
    
    bool isEmpty() {
        return (size == 0);
        
    }
    
    bool isFull() {
        return size == cap;
    }
};

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