class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<char>v(26,0);
        for(auto it: sentence) v[it-'a']=1;
        for(auto it: v) if(it==0) return 0;
        return 1;
    }
};