class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int>st1;
        int n =s.size();
        int j=0;

        int maxs =0;
        for(int i=0;i<n;i++){
            while (st1.find(s[i]) != st1.end()) {
                st1.erase(s[j]);
                j++;
            }

            st1.insert(s[i]);
            maxs = max(maxs, i - j + 1);
        }
        return maxs;
    }
};