class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> temp;
        for (auto const t:tokens) {
            if (!temp.empty() && t == "+" || t == "-" || t == "*" || t == "/") {
                int second = temp.back();
                temp.pop_back();
                int first = temp.back();
                temp.pop_back();
                int res = 0;
                
                if (t == "+") res = first + second;
                if (t == "-") res = first - second;
                if (t == "*") res = first * second;
                if (t == "/") res = first / second;
                
                temp.push_back(res);
            } else temp.push_back(stoi(t));
        }
        
        return temp.back();
    }
};