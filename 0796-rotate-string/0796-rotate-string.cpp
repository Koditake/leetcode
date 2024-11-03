class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        // Create a new string by concatenating 's' with itself
        string doubledString = s + s;

        return doubledString.find(goal) < doubledString.length();
    }
};