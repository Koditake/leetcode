class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);

        int maxidx = -1,
            maxdigit = -1,
            leftidx = -1,
            rightidx = -1;

        for (int i = str.length() - 1; i >= 0; --i) {
            if (str[i] > maxdigit) {
                maxdigit = str[i];
                maxidx = i;
                continue;
            }

            if (str[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        if (leftidx == -1)
            return num;

        std::swap(str[leftidx],str[rightidx]);

        return stoi(str);
    }
};