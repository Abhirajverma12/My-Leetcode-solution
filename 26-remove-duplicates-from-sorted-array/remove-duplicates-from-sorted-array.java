class Solution {
    public int removeDuplicates(int[] nums) {
        int indx = 0;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[indx]) {
                indx++;
                nums[indx] = nums[i];
            }
        }
        
        return indx + 1;
    }
}