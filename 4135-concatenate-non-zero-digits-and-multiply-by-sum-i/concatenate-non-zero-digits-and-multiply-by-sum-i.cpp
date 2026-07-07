class Solution {
public:
    long long sumAndMultiply(int n) {
        int x= 0;
        int sum =0;
        int num =0;
        while(n!= 0){
            int rem = n%10;
            if(rem != 0 ){
                sum += rem;
                num = (num*10);
                num += rem;
            }
            n = n/10;
        }
        n= 0;
        while(num!=0){
            int rem = num%10;
            n = (n*10)+rem;
            num /= 10;
        }
        long long ans = (long long)n * (long long)sum;
        return ans;
    }
};