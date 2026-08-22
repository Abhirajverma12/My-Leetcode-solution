class Solution {
    public int maxFrequencyElements(int[] nums) {
        // we intialize the HashMap in java as alternate of the unordered_map in c++ 
        HashMap<Integer,Integer>freq = new HashMap<>();
         
         // in java we count the freq of each character and now we if already exists than we increase count and not exists so simply put 1 count to it 
        for(int i:nums){
            if(freq.containsKey(i)){
                freq.put(i,freq.get(i)+1);
            }
            else{
                freq.put(i,1);
            }
        }
        int maxv = Integer.MIN_VALUE;

        // here we find the max frequency ..
        for(int value:freq.values()){
            maxv = Math.max(value,maxv);
        }

        int sum= 0;
        for(Map.Entry<Integer,Integer> entry : freq.entrySet()){
            int key = entry.getKey();
            int value = entry.getValue();
            if(value == maxv){
                sum += value;
            }
        }

        return sum ;

    }
}