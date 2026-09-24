class Solution {
public:
int digitsum(int digit){
    int sum = 0;
    while(digit){
        sum += digit%10 ;
        digit = digit/10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int sum = digitsum(nums[i]);
            if(sum == i) return i;
        }
        return -1;
    }
};