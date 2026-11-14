class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int prvindx =0;
        int maxlen = 0;
        int j=0;
        vector<int>lastseen(256,-1);
        for(int i=0;i<n;i++){
            if(lastseen[s[i]] != -1){
                j  = max(j,lastseen[s[i]]+1);
            }
            lastseen[s[i]]=i;
            maxlen = max(maxlen,i-j+1);
        }
        return maxlen;
    }
};