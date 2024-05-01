class Solution {
public:
    auto reverseWord(std::string word) -> std::string {
        // in-place word reverse
        int left = 0, right = word.size() - 1;
        while (left < right) {
            std::swap(word[left], word[right]);
            left++;
            right--;
        }
        return word;
    }
    
    string reversePrefix(string word, char ch) {
        std::string res = {};
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                res = reverseWord(word.substr(0,i+1));
                res += word.substr(i+1,word.size() - i);
                break;
            }
        }
        
        return (res.empty())?word:res;
    }
};