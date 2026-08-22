class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;
        ArrayList<Integer> arr = new ArrayList<>();

        while(x!=0){
            int val = x%10;
            arr.add(val);
            x /=10;
        }
        int n = arr.size();
        for(int i=0;i<n/2;i++){
            if(arr.get(i) != arr.get(n-1-i)){
                return false;
            }
        }
        return true;
    }
}