/*
    Make a histogram out of two hashmaps, compare each element freqency

    Time: O(m + n)
*/

#include <unordered_map>
#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> mp, mp1;
        for (char i : s)
            mp[i]++;
        for (char i : t)
            mp1[i]++;
        if (mp.size() != mp1.size())
            return false;
        for (auto i : mp1)
        {
            if (mp[i.first] != mp1[i.first])
                return false;
        }
        return true;
    }
};
