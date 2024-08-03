class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if (arr.size() <= 1) 
            return target == arr;
        
        unordered_map<int, int> imap;
        
        for (int i = 0; i < arr.size(); i++) {
            ++imap[target[i]];
            --imap[arr[i]];
        }
        
        for (auto &[num,freq]:imap)
            if (freq != 0)
                return false;
        
        return true;
    }
};