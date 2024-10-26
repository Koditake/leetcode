class MinStack {
public:
    MinStack() {
        
    }
    
    ~MinStack() {
        
    }
    
    void push(int val) {
        if (min.empty() || val <= min.top()) min.push(val);
        main.push(val);
    }
    
    void pop() {
        if (!min.empty() && main.top() == min.top())
            min.pop();
        main.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return min.top();
    }
private:
    stack<int> main;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */