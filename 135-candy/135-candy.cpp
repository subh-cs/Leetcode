class Solution {
public:
    int candy(vector<int>& r) {
        if(r.size()==1) return 1;
        vector<int> ans(r.size(),1);
        for(int i=1;i<r.size();i++)
            if(r[i]>r[i-1]) ans[i]=(ans[i-1]+1);
        for(int i=r.size()-1;i>0;i--)
            if(r[i]<r[i-1]) ans[i-1]=max(ans[i]+1,ans[i-1]);
        return accumulate(begin(ans),end(ans),0);  
    }
};