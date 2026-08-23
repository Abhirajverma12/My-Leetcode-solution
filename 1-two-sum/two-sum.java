class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer>mpp = new HashMap<>();

        int n = nums.length;
        int findx =-1;
        int sindx =-1;
        for(int i=0;i<n;i++){
            int needed = target - nums[i];
            if(mpp.containsKey(needed)){
                findx = mpp.get(needed);
                sindx = i;
                break;
            }
            mpp.put(nums[i],i);
        }
        return new int[]{findx,sindx};
    }
}