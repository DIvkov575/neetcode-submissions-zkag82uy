class MyQueue {
    vector<int> sa;
    vector<int> sb;

public:
    MyQueue() { }
    
    void push(int x) {
        sa.push_back(x);
    }
    
    int pop() {
        while (sa.size() > 1) {
            sb.push_back(sa[sa.size()-1]);
            sa.pop_back();
        }
        int ret = sa[0];
        sa.pop_back();
        while (!sb.empty()) {
            sa.push_back(sb[sb.size()-1]);
            sb.pop_back();
        }

        return ret;
    }
    
    int peek() {
        while (sa.size() > 1) {
            sb.push_back(sa[sa.size()-1]);
            sa.pop_back();
        }
        int ret = sa[0];
        sb.push_back(sa[sa.size()-1]);
        sa.pop_back();

        while (!sb.empty()) {
            sa.push_back(sb[sb.size()-1]);
            sb.pop_back();
        }

        return ret;
        
    }
    
    bool empty() {
        return sa.size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */