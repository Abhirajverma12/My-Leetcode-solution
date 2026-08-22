class Solution {
    public int maximumCount(int[] nums) {
        int pv =0;
        int nv =0;
        for(int i:nums){
            if(i<0){
                nv++;
            }
            else if(i>0){
                pv++;
            }
        }
        return pv>nv?pv:nv;
    }
}