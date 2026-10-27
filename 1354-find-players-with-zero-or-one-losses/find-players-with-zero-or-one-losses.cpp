class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>freq1,freq2;

        for(auto it :matches){
            freq1[it[0]]++;
            freq2[it[1]]++;
        }
        vector<vector<int>>ans;
        vector<int>temp1 , temp2;

        for(auto it :freq1){
            if( freq2.find(it.first)==freq2.end()){
                temp1.push_back(it.first);
            }
        }

        for(auto it : freq2){
            if(it.second==1){
                temp2.push_back(it.first);
            }
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        ans.push_back(temp1);
        ans.push_back(temp2);

        return ans;

    }
};