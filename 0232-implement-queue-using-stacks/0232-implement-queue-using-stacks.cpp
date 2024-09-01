class MyQueue {
    stack<int> stk1, stk2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk1.push(x);
    }
    
    int pop() {
        if (stk2.empty()) transmute();
        int tmp = 0;
        if (!stk2.empty()) {
            tmp = stk2.top();
            stk2.pop();
        }
        
        return tmp;
    }
    
    int peek() {
        if (stk2.empty()) transmute();
        if (!stk2.empty()) {
            return stk2.top();
        }
        
        return 0;
    }
    
    void transmute() {
        while (!stk1.empty()) {
            stk2.push(stk1.top()); stk1.pop();
        }
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
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