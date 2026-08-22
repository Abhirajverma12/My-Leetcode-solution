class Solution {
    public int countOdds(int low, int high) {
        int rangv = high -low ;

        rangv /= 2 ;
        if(low%2 != 0 && high%2 != 0) return rangv+1;
        if(low%2 != 0) rangv++;
        if(high%2 != 0) rangv++;

        return rangv;
    }
}