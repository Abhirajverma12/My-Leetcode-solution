class Solution {
public:
//  in this question we take refrence from the 930 no. question , using same approach 
// in this we treat odd number as 1  and even number as 0  and k as goal 
    int atMost(vector<int>& nums, int k){
        if(k<0) return 0;
        int cnt=0;
        int n =nums.size();
        int l= 0;
        int r=0;
        int sum=0;
        while(r<n){
            sum += (nums[r]%2);
            while(sum > k){
                sum -= (nums[l]%2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,(k-1));
    }
};