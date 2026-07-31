class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>freq;
        for(auto it :word){
            freq[it]++;
        }
        // Store (character, frequency) pairs
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort by frequency in descending order
        sort(vec.begin(), vec.end(),
             [](const pair<char, int>& a, const pair<char, int>& b) {
                 return a.second > b.second;
             });

        
        int ans =0;
        for(int i=0;i<vec.size();i++){   
            
            int val = vec[i].second;
            if(i<8){ ans += (1*val);}
            else if(8<=i && i<16){ans+=(2*val);}
            else if(16<=i && i<24){ans += (3*val);}
            else {ans += (4*val);}
            
        }
        return ans;

    }
};