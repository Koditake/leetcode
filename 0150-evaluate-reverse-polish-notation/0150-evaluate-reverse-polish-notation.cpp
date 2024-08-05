class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> store;
        
        for (auto &t:tokens) {
            if (t.size() > 1 || isdigit(t[0])) {
                store.push_back(stoi(t));
            } else {
                int n2 = store.back(); store.pop_back();
                int n1 = store.back(); store.pop_back();
                switch (t[0]) {
                    case '+': store.push_back(n1 + n2); break;
                    case '-': store.push_back(n1 - n2); break;
                    case '*': store.push_back(n1 * n2); break;
                    case '/': store.push_back(n1 / n2); break;
                    defalt: continue; break;
                }
            }
        }
        
        return store.back();
    }
};