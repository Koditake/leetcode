class Solution {
public:
    string countOfAtoms(string formula) {
        //stack? 
        std::map<string, int> stats;
        std::reverse(formula.begin(), formula.end());
        compute(formula, stats);
        string result;
        
        for (auto& kv : stats) {
            result += kv.first;
            if (kv.second > 1) {
                result += std::to_string(kv.second);
            }
        }
        return result;
    }
    
private: // K4(ON(SO3)2)2
    auto compute(string& formula, std::map<string, int>& stats) -> void {
        int n = formula.size();
        
        std::stack<int> stk; // factor
        stk.push(1);
        
        string elem; // chemical element, e.g., C, N, O, Na, Mg, Al, etc.
        int factor = 1; // number of this element, default to 1 if not otherwise specified
        
        for (int i = 0; i < n; ++i) {
            auto& c = formula[i];
            if (isdigit(c)) { // E.g., original 312 was reverse to 213.
                int val = 0, expo = 1;
                do {
                    val += (c - '0') * expo;
                    ++i; expo *= 10;
                } while (isdigit(c = formula[i]));
                factor = val; // explicit number of this element
                
                i -= 1;
            } else if (c == ')') { 
                stk.push(factor * stk.top());
                factor = 1; //            Al(OH)3
            } else if (c >= 'A' && c <= 'Z') {
                elem += c;
                std::reverse(elem.begin(), elem.end());
                stats[elem] += factor * stk.top();
                factor = 1;
                elem.clear();
            } else if (c >= 'a' && c <= 'z') {
                elem += c;
            } else { // (c == '(') {  
                stk.pop();  // Ca(OH)2
                // elem.clear();
            } 
        }   
    }
};