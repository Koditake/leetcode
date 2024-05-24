class Solution {
public:
    bool isValid(string s) {
        std::stack<char> cstk;
        
        for (auto &c:s) {
            if (!cstk.empty() && 
                       ((cstk.top() == '(' && c == ')') || 
                       (cstk.top() == '[' && c == ']') || 
                       (cstk.top() == '{' && c == '}'))
                      ) {
                    cstk.pop();
                }  else
                cstk.push(c);
        }
        return cstk.empty();
    }
};