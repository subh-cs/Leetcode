class Solution {
public:
    int lengthOfLongestSubstring(string v) {
        if(v.length()==0) return 0;
        int maxcount=1;int n=v.size();
        for(int i=0;i<n;++i){
            set<int>s;
            for(int j=i;j<n;++j){
                if(s.count(v[j])==0) s.insert(v[j]);
                else break;  
            }
            int num=s.size();
            maxcount=max(maxcount,num);
        }
        return maxcount;
    }
};