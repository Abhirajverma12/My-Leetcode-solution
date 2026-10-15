class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // boyer-moore-algorithm
        int maj,count=0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                maj =nums[i];
                count++;
            }
            else if(maj == nums[i]) count++;
            else count--;
        }
        return maj;
    }
};