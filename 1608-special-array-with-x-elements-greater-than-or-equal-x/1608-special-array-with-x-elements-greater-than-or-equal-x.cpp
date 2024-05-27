class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i=1, j=nums.size();
		while(i<=j){
			int mid=i+(j-i)/2, cnt=0;
			for(int k=0; k<nums.size(); k++){
				if(nums[k]>=mid){cnt++;}
			}
			if(cnt==mid){return mid;}
			else if(cnt<mid){j=mid-1;}
			else{i=mid+1;}
		}
		return -1;
    }
};