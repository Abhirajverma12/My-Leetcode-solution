class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        int n = s.size();
        
        for(char & ch : s){
            
            if(st.empty() || ch =='(' || ch == '{' || ch == '['){
                st.push(ch);
                continue;
            }
            
            if(ch == ')'){
                if(st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }
            
            if(ch == '}'){
                if(st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }
            
            if(ch == ']'){
                if(st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }
            
        }
        if(!st.empty()){
            return false;
        }
        
        return true;
    }
};