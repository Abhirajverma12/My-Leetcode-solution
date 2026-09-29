class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp =0;
        int bp = prices[0];

        for(int i=1;i<prices.size();i++){
            int currp = prices[i]-bp ;
            maxp = max(maxp, currp);
            bp = min(bp,prices[i]);
        }
        return maxp;
    }
};