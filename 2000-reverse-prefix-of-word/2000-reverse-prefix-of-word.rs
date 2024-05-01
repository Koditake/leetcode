class Solution {
public:
    auto reverseWord(std::string &word, int right) -> void {
        // in-place word reverse
        int left = 0;
        while (left < right) {
            std::swap(word[left], word[right]);
            left++;
            right--;
        }
    }
    
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == ch) {
                reverseWord(word,i);
                break;
            }
        }
        
        return word;
    }
};