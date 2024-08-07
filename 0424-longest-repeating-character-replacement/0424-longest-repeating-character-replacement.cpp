class Solution {
public:
    int characterReplacement(string s, int k) {
        int end = 0;
        int start = 0;
        
        int max_len = 0;
        int max_count_in_window = 0;
        
        unordered_map<char,int> count;
        
        for(end = 0; end < s.size(); end++)
        {
            count[s[end]]++;
            max_count_in_window = max(count[s[end]], max_count_in_window);
            if(end - start + 1 - max_count_in_window > k)
            {
                count[s[start]]--;
                start++;
            }
            max_len = max(max_len, end - start + 1);
        }
        
        return max_len;
    }
};