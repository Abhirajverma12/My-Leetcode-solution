class Solution {
public:
    void solve_ans(int indx, vector<int>& lst,vector<vector<int>>& ans,int sum ,vector<int>& candidates){
        if(sum == 0 ){
            ans.push_back(lst);
            return ;
        }
        if(sum<0 || indx >=candidates.size()){return ;}

        lst.push_back(candidates[indx]);
        solve_ans(indx ,lst,ans,sum-candidates[indx] , candidates );
        lst.pop_back();

        solve_ans(indx+1,lst,ans,sum , candidates );

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>lst;
        vector<vector<int>>ans;

        solve_ans(0, lst,ans,target,candidates);
        return ans;
    }
};