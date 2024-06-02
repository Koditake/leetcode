class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0,
            right = s.size() - 1;
        char swap;
        while (left < right) {
            swap = s[right];
            s[right] = s[left];
            s[left] = swap;
            left++;
            right--;
        }
    }
};