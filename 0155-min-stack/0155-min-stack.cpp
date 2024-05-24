class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> subStack;
public:
    MinStack() {
        // default constructor
    }
    
    void push(int val) {
        if (subStack.empty()) {
            subStack.push(val);
        } else 
        if (subStack.top() >= val) {
            subStack.push(val);
        }

        mainStack.push(val);
    }
    
    void pop() {
        if (mainStack.top() == subStack.top() && !subStack.empty()) {
            subStack.pop();
        }

        mainStack.pop();
    }
    
    int top() {
        if (!mainStack.empty())
            return mainStack.top();
        
        return 0;
    }
    
    int getMin() {
        if (!subStack.empty())
            return subStack.top();
        
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */