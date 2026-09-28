class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minl = INT_MAX;
        
        int currsum =0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];

            while(currsum >= target){
                int currlen = i-j+1;
                minl = min(minl,currlen);
                currsum -= nums[j];
                j++;
            }
        }
        return minl==INT_MAX ? 0 : minl;  
    }
};