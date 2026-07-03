class MyStack {
    deque<int> dqa;
    deque<int> dqb;
public:
    MyStack() {  }
    
    void push(int x) {
        while (!dqa.empty()) {
            dqb.push_back(dqa.front());
            dqa.pop_front();
        }
        dqa.push_back(x);
    }
    
    int pop() {
        int ret_val = dqa.front();
        dqa.pop_front();
        while (!dqb.empty()) {
            dqa.push_back(dqb.front());
            dqb.pop_front();
        }

        while (dqa.size() > 1) {
            dqb.push_back(dqa.front());
            dqa.pop_front();
        }

        return ret_val;
    }
    
    int top() {
        return dqa.front();
    }
    
    bool empty() {
        return (dqa.size() + dqb.size()) == 0;
        
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