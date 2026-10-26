class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt=0;
        long prefixsum =0;
        long rem=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i =0;i<nums.size();i++){
        prefixsum +=nums[i];
        rem = prefixsum - k ;
        if(mpp.find(rem)!=mpp.end()){cnt +=mpp[rem]; }
        mpp[prefixsum]+=1;
    }
    return cnt;
    }
};