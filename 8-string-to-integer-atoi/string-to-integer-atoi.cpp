class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int cnt = 0 , sign = 1 ;
        long long ans =0;
        int i=0;
        while( i < n && s[i] == ' '){i++;}
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        while(i<n &&   isdigit(s[i]) ){
            int temp = s[i]-'0';

            if (ans > (INT_MAX - temp) / 10) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            ans = ans*10 + temp;
            i++;
        }
        return ans*sign;
    }
};