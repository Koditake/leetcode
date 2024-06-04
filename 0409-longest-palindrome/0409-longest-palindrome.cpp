class Solution {
public:
    int longestPalindrome(string s) {
        //naive solution
        //make a histogram of the characters
        //a palindrome can be constructed from the even number of character PLUS a core (if possible)
        if (s.size() == 1) return 1;
        vector<int> histogramLowerCase(26,0), histogramUpperCase(26,0);
        for (auto c:s) {
            if (islower(c))
            {
                histogramLowerCase[c-'a']++;
            }
            else if (isupper(c))
            {
                histogramUpperCase[c-'A']++;
            }
            
        }
        int hasCoreCharacter = 0; int palindromeConstruct = 0;

        for(auto i:histogramLowerCase)
        {
            if ((hasCoreCharacter < 1)&& (i%2 > 0)) //If the palimdrome as a core of one ODD-count characters. One pass only
            {
                hasCoreCharacter++;
            }
            palindromeConstruct += (i/2)*2;
        }

        for(auto i:histogramUpperCase)
        {
            if ((hasCoreCharacter < 1)&& (i%2 > 0)) //If the palimdrome as a core of one ODD-count characters. One pass only
            {
                hasCoreCharacter++;
            }
            palindromeConstruct += (i/2)*2;
        }
        return palindromeConstruct + hasCoreCharacter;
    }


};