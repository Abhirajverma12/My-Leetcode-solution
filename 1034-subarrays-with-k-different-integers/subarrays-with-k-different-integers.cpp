class Solution {
public:
int cntfind(vector<int>&nums,int k){
    unordered_map<int,int>mpp;
        int cnt =0;
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i])!= mpp.end()){
                mpp[nums[i]]++;
            }else{
                mpp[nums[i]] =1;
            }

                while(mpp.size()>k && j <nums.size()){
                    mpp[nums[j]]--;
                    
                    if (mpp[nums[j]] == 0) {
                        mpp.erase(nums[j]);
                    }
                    j++;
                }
            
            cnt += (i-j+1);

        }
        return cnt ;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ek = cntfind(nums,k);
        int ekl = cntfind(nums, k-1);
        return ek-ekl;
    }
};