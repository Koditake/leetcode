class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        
        for i in range(0,len(words)):
            if words[i].startswith(searchWord):
                return i + 1
        
        return -1
        