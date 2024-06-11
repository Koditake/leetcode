class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(),
            n = arr2.size();
        
        std::vector<int> arr3;
        
        // give us map with asc order
        std::map<int, int> maparr1;
        
        // count element freq in arr1
        for (auto &i:arr1) {
            ++maparr1[i];
        }
        
        // for every element in arr2, push all instance of that element from maparr1 into arr3
        for (auto &indx:arr2) {
            while (maparr1[indx] > 0) {
                arr3.push_back(indx);
                --maparr1[indx];
            }
        }
        
        // for every element remain freq > 0, push all instance of that element
        // since we use ordered map, the order will be automatically calculated
        for (auto &[indx, freq]:maparr1) {
            if (freq > 0) {
                for (int i = 0; i < freq; i++) {
                    arr3.push_back(indx);
                }
            }
        }
        
        return arr3;
    }
};