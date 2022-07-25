class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int maxcount=1, n=s.size();
        map<char,int>m;
        int i=0,j=0;
        while(j<n){
            m[s[j]]++;
            if(m.size()==j-i+1){
                maxcount=max(maxcount,j-i+1);
            }
            else if(m.size()<j-i+1){
                while(m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0) m.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxcount;
    }
};