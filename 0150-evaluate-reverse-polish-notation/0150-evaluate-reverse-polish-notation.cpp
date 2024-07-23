class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n1, n2;
        for (auto &tok:tokens) {
            if (tok == "+") {
                n2 = stk.top(); stk.pop();
                n1 = stk.top(); stk.pop();
                stk.push(n1 + n2);
            } else if (tok == "-") {
                n2 = stk.top(); stk.pop();
                n1 = stk.top(); stk.pop();
                stk.push(n1 - n2);
            } else if (tok == "*") {
                n2 = stk.top(); stk.pop();
                n1 = stk.top(); stk.pop();
                stk.push(n1 * n2);
            } else if (tok == "/") {
                n2 = stk.top(); stk.pop();
                n1 = stk.top(); stk.pop();
                stk.push(n1 / n2);
            } else {
                stk.push(stoi(tok));
            }
        }
        
        return stk.top();
    }
};