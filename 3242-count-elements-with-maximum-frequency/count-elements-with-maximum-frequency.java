class Solution {
    public int maxFrequencyElements(int[] nums) {
        // use "var" rather than "HashMap<Integer,Integer> entry" while traverse in the hashmap while traversing 
        HashMap<Integer,Integer>freq = new HashMap<>();

        for(int i:nums){
            if(freq.containsKey(i)){
                freq.put(i,freq.get(i)+1);
            }else{
                freq.put(i,1);
            }
        }

        int maxv = 0;
        for(var entry : freq.entrySet()){
            int key = entry.getKey();
            int value = entry.getValue();
            maxv = Math.max(maxv,value);
        }
        int ans =0;
        for(var entry : freq.entrySet()){
            int key = entry.getKey();
            int value = entry.getValue();
            if(value == maxv){
                ans += value;
            }
        }
        return ans;
    }
}