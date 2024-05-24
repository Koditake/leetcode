class Solution {
public:
     void backtracking(std::vector<string>& words, std::vector<int>& score, std::vector<int>& count, std::vector<int>& lettersCount, int pos, int temp, int &ans) {
        for (int i = 0; i < 26; i++){
            if(lettersCount[i] > count[i]) return;
        }
        ans = max(ans, temp);
        for (int i = pos; i < words.size(); i++){
            for(auto& c : words[i]){
                lettersCount[c - 'a']++;
                temp += score[c - 'a'];
            }
            backtracking(words, score, count, lettersCount, i + 1, temp, ans);
            for(auto& c : words[i]){
                lettersCount[c - 'a']--;
                temp -= score[c - 'a'];
            }
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        std::vector<int> count(26, 0); 
        std::vector<int> lettersCount(26, 0);
        for(auto &c : letters) {
            count[c - 'a']++;
        }
        int ans = 0;
        backtracking(words, score, count, lettersCount, 0, 0, ans);
        return ans;
    }
   
};