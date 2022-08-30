class Solution {
public:
    int totalFruit(vector<int>& f) {
        //k =2 always
        unordered_map<int,int>m;
        int i=0,j=0,n=f.size(),ans=0;
        
        while(j<n){
            m[f[j]]++;
            if(m.size()<=2)
                ans=max(ans,j-i+1);
            else if(m.size()>2){
                while(m.size()>2){
                    m[f[i]]--;
                    if(m[f[i]]==0) m.erase(f[i]);
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};