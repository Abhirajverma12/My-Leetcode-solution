class Solution {
public:
    bool isPalindrome(int x) {
        int i,n;
        n=x;
        unsigned int rev=0;
        int reminder=0;
        if(x<0){
            return 0;
        }
        while(n!=0){
            reminder = n%10;
            rev = rev*10 + reminder;
            n=n/10;
        }
        
        if(rev == x)
            return (x==rev || x==rev/10);
        else
            return false; 
    }
};