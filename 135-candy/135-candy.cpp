class Solution {
public:
    int candy(vector<int>& r) {
        //
        if(r.size()==1) return 1;
        if(r.size()==2 && r[0]==r[1]) return 2;
        if(r.size()==2) return 3;
        //
        vector<int> ans(r.size(),1);
        // once traverse from left and keep track of right neighbours
        for(int i=1;i<r.size();i++)
            if(r[i]>r[i-1]) ans[i]=(ans[i-1]+1);
        // traverse from right and keep track from left neighbours 
        for(int i=r.size()-1;i>0;i--)
            if(r[i]<r[i-1]) ans[i-1]=max(ans[i]+1,ans[i-1]);
        
        int sum = accumulate(begin(ans),end(ans),0);
        return sum;
    }
};