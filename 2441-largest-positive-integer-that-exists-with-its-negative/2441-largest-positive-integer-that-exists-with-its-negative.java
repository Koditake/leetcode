class Solution {
    public int findMaxK(int[] nums) {
        Set<Integer> set = new HashSet();
        for(int data: nums){
            if(data < 0){
                set.add(data);
            }
        }

        int ans = -1;
        for(int data: nums){
            if(data > 0 && set.contains(-data)){
                ans = Math.max(ans, data);
            }
        }

        return ans;
    }
}