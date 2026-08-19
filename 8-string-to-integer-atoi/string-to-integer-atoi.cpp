class Solution {
public:

    long long convert(string &s, int i, long long ans, int sign) {

        // Base case
        if (i >= s.size() || !isdigit(s[i])) {
            return ans * sign;
        }

        int digit = s[i] - '0';

        // Overflow check
        if (sign == 1 && ans > (INT_MAX - digit) / 10)
            return INT_MAX;

        if (sign == -1 && ans > (-(long long)INT_MIN - digit) / 10)
            return INT_MIN;

        ans = ans * 10 + digit;

        return convert(s, i + 1, ans, sign);
    }

    int myAtoi(string s) {

        int i = 0;

        // 1. Skip spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // 2. Sign
        int sign = 1;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;

            i++;
        }

        // 3. Recursively process digits
        return convert(s, i, 0, sign);
    }
};