class Solution {
public:
    void solve(int n , string str ,int o ,int c ,vector<string>&ans){
        // base case: if no open and close left, push result
        if(o ==0 && c == 0){
            ans.push_back(str);
            return ;
        }
        // if we still have opening brackets, add one
        if(o > 0){
            solve(n, str+"(" ,o-1,c,ans);
        }
        // add closing bracket only if more closing left than opening
        if(c > 0 &&  c>o ){
            solve(n,str+")",o,c-1,ans);
        }
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        string str= "";
        solve(n,str,n,n,ans);
        return ans;
    }
};