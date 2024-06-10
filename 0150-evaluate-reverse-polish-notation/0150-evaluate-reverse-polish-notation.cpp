class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> decoder;

        for (std::string &s:tokens) {
            if (s.size() > 1 || isdigit(s[0])) {
                decoder.push(stoi(s));
            } else if (s == "+" || s == "-" || s == "*" || s == "/") {
                int operandTwo = decoder.top();
                decoder.pop();
                int operandOne = decoder.top();
                decoder.pop();
                int result;

                if (s == "+") {
                    result = operandOne + operandTwo;
                } else if (s == "-") {
                    result = operandOne - operandTwo;
                } else if (s == "*") {
                    result = operandOne * operandTwo;
                } else if (s == "/") {
                    result = operandOne / operandTwo;
                }
                decoder.push(result);
            }
        }

        return decoder.top();
    }
};