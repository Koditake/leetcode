class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        std::set<string> s (begin(dictionary), end(dictionary));
        std::istringstream iss(sentence);
        std::vector<string> temp;
        std::string word, res; 

        while (iss >> word) 
            temp.push_back(word);
        
        for (string &t:temp) {
            int i = 0;
            while( i++ <= t.size()) {
                string curr = t.substr(0, i);
                if(s.find(curr) != s.end()) {
                    res += curr + " ";
                    break;
                }
                
                if(i == t.size()) res += curr + " ";
            }
        }

        res.erase(res.size() - 1);
        
        return res;
    }
};