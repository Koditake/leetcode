class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int co = 0;
        for(int i = 0; i < arr.size(); i++) {
            int c = 0;
            for(int j = 0;j < arr.size(); j++)
                if(arr[i] == arr[j])
                    c++;
            if (c == 1) co++;
            if (co == k) return arr[i];
        }
        return "";
    }
};