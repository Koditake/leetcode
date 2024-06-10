class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int res = 0; 
        std::vector<int> count(101, 0);

        for (int i = 0; i < heights.size(); i++) count[heights[i]]++;

        int i = 1, j = 0; 
        while (i < 101){
			// check value of count
            if(count[i] == 0){
                i++;
            } else {
				// compare the index of count with value of height
                if (i != heights[j]) 
                    res++;
                j++; 
                count[i]--;
            }
        }

        return res;
    }
};