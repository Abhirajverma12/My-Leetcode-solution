class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxnum = *max_element(nums.begin(),nums.end());
        int minnum = *min_element(nums.begin(),nums.end());
        int ans=1;
        for(int i=2;i<=maxnum;i++){
            if((maxnum%i == 0 ) && (minnum%i == 0)){
                ans =i;
            }
        }
        return ans;
    }
};