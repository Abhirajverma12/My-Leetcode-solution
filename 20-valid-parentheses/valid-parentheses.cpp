class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int n = s.size();
        
        for(char & ch : s){
            
            if(st.empty() || ch =='(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                char chst = st.top();
                if(st.empty()) {return false;}
                else if((chst == '(' && ch ==')') || (chst =='[' && ch ==']') || (chst =='{' && ch =='}')){
                   st.pop(); 
                }
                else{
                    return false ;
                }
            }
            
        }
        if(!st.empty()){
            return false;
        }
        
        return true;
    }
};