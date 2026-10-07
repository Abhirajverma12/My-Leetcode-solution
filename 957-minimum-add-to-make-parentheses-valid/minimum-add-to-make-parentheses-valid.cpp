class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int cl =0;
        int op =0;

        for(auto it :s){
            if(it == '('){
                op++;
            }
            else{
                if(op!=0){
                    op--;
                }else{
                    cl++;
                }
            }
        }
        return cl+op;
    }
};