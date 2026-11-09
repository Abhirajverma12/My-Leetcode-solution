class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int l = 0 , r = m-1;
        int t = 0 , b = n-1;
        vector<int>vec;
        while(l<=r && t<=b){
            // Left to right
            for(int i=l;i<=r;i++){
                vec.push_back(matrix[t][i]);
            }
            t++;
            // right to bottom 
            for(int i = t;i<=b;i++){
                vec.push_back(matrix[i][r]);
            }
            r--;

            //bottom to left
            if(t<=b){ 
            for(int i =r;i>=l;i--){
                vec.push_back(matrix[b][i]);
            }b--;
        }
            // left to top
            if(l<=r){
            for(int i = b;i>=t;i--){
                vec.push_back(matrix[i][l]);
            }l++;}
        }
        return vec;
    }
};