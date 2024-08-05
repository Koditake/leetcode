class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> store;
        
        for (auto const &t:tokens) {
            if (t == "+") {
                int n2 = store.back(); store.pop_back();
                int n1 = store.back(); store.pop_back();
                store.push_back(n1 + n2);
            } else if (t == "-") {
                int n2 = store.back(); store.pop_back();
                int n1 = store.back(); store.pop_back();
                store.push_back(n1 - n2);
            } else if (t == "*") {
                int n2 = store.back(); store.pop_back();
                int n1 = store.back(); store.pop_back();
                store.push_back(n1 * n2);
            } else if (t == "/") {
                int n2 = store.back(); store.pop_back();
                int n1 = store.back(); store.pop_back();
                store.push_back(n1 / n2);
            } else {
                store.push_back(stoi(t));
            }
        }
        
        return store.back();
    }
};