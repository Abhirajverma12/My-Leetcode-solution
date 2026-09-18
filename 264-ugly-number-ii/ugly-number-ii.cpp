class Solution {
public:
    int nthUglyNumber(int n) {
        long long ugly =1;
        int p2 =0 , p3 =0 , p5 =0;
        vector<int>vec;
        vec.push_back(1);
        for(int i=1;i<n;i++){
            int u1 = vec[p2]*2;
            int u2 = vec[p3]*3;
            int u3 = vec[p5]*5;
            ugly = min(u1,min(u2,u3) );
            vec.push_back(ugly);
            if(ugly == u1) p2++;
            if(ugly == u2) p3++;
            if(ugly == u3) p5++;

        }
        return ugly;
    }
};