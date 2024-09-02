class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n= chalk.size();
        long long arr[n];
        arr[0]= chalk[0];
        for (int i=1; i<n; i++)arr[i]=arr[i-1]+ chalk[i];
        k = k%arr[n-1];
        // just greater than k;
        int low=0; int high= n-1;
        //int ans=0;
        while (low<=high){
            int mid= low + (high-low)/2;
            if (arr[mid]> k){
                //ans= mid;
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};