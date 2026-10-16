
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long maxprod = nums[0];
        long long maxcurr = nums[0];
        long long mincurr = nums[0];

        for (int i = 1; i < n; i++) {
            long long x = nums[i];
            long long tempMax = maxcurr;

            maxcurr = max(x, max(x * maxcurr, x * mincurr));
            mincurr = min(x, min(x * tempMax, x * mincurr));

            maxprod = max(maxprod, maxcurr);
        }

        return (int)maxprod;
    }
};
