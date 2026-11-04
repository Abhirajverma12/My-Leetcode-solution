class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        HashSet<Integer>st = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();
        for(int n :nums){
            if(st.contains(n)){
                ans.add(n);
            }else {
                st.add(n);
            }
        }
        return ans;
    }
}