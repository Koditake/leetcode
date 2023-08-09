/*
    Assume that we only deal with lowercase english characters, there is only 25 unique character. We can map them into an array with 'a' = 0, 'b' = 1,... , 'z' = 24

    Each char of s we increase freq by 1, and decrease t by 1.

    In the end, if all 25 elements are 0 we can declare them anagram
*/

#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.length() != t.length())
            return false;
        int n = s.length();

        int counts[26] = {0};

        memset(counts, 0, sizeof counts);
        
        for (int i = 0; i < n; i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i])
                return false;
        return true;
    }
};