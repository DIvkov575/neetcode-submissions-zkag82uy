class MyStack {
    deque<int> dqa;
    deque<int> dqb;
public:
    MyStack() { }
    
    void push(int x) {
        dqa.push_back(x);
    }
    
    int pop() {
        while (dqa.size() > 1) {
            dqb.push_back(dqa.front());
            dqa.pop_front();
        }
        int ret_val = dqa.front();
        dqa.pop_front();
        while (!dqb.empty()) {
            dqa.push_back(dqb.front());
            dqb.pop_front();
        }
        return ret_val;
    }
    
    int top() {
        while (dqa.size() > 1) {
            dqb.push_back(dqa.front());
            dqa.pop_front();
        }
        int ret_val = dqa.front();
        dqb.push_back(dqa.front());
        dqa.pop_front();

        while (!dqb.empty()) {
            dqa.push_back(dqb.front());
            dqb.pop_front();
        }
        
        return ret_val;
    }
    
    bool empty() {
        return dqa.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */