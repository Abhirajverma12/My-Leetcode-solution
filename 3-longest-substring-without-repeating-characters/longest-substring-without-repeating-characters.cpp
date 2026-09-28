class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j=0;
        unordered_map<int,int>freq ;
        int n = s.size();
        int maxv = 0;

        for(int i=0;i<n;i++){
            freq[s[i]]++;
            while(freq[s[i]]> 1){
                freq[s[j]]--;
                j++;
            }

            int curr  = i-j+1 ;
            maxv = max(maxv, curr);
        }

        return maxv ;
    }
};