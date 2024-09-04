class Solution {
public:
    int sumDigits(const string& s) {
        int sum = 0;
        for (char c : s) {
            sum += c - '0';  // Convert character to integer and sum
        }
        return sum;
    }

    int getLuckyRecursive(string s, int k) {
        if (k == 0) {
            return stoi(s);  // Base case: no more operations to perform
        }

        // Convert string to number by summing digits
        int sum = sumDigits(s);

        // Convert the sum back to string for the next recursion
        return getLuckyRecursive(to_string(sum), k - 1);
    }

    int getLucky(string s, int k) {
        // Convert the initial string to its numeric representation
        string str = "";
        for (char c : s) {
            str += to_string(c - 'a' + 1);
        }

        // Call the recursive function
        return getLuckyRecursive(str, k);
    }
};