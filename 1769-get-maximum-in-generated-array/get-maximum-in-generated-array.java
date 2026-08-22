class Solution {
    public int getMaximumGenerated(int n) {
        int[] arr = new int[n+1];
        if(n==0 || n==1){
            return n;
        }
        arr[0]=0;
        arr[1]=1;

        for(int i =0;i<=(n/2);i++){
            int val = 2*i;
            if(val<n+1)arr[val] = arr[i];
            if(val+1 < n+1)arr[val+1] = arr[i]+arr[i+1];
        }
        int maxv = Integer.MIN_VALUE;

        for(int i:arr){
            maxv = Math.max(maxv,i);
        }
        return maxv;
    }
}