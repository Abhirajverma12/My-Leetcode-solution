class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total_Range = n*n;
        unordered_map<int,int>freq ;
        for(int i=0;i<n;i++){
            for(int j =0;j<grid[i].size();j++){
                freq[grid[i][j]]++;
            }
        }
        int mis =-1;
        int extra =-1;
        for(int i=1;i<=n*n;i++){
            if(freq.find(i)==freq.end()){
                mis = i;
            }else{
                if(freq[i]==2){
                    extra = i;
                }
            }
        }
        return {extra,mis};
    }
};