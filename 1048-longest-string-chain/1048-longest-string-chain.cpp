 bool check(string &a,string &b){
        if(a.size()!=b.size()-1) return false;
        bool foo=true;
        int i=0,j=0,n=a.size(),m=b.size();
        while(i<n && j<m){
            if(a[i]==b[j]) i++,j++;
            else if(foo) foo=false,j++;
            else break;
        }
        if(foo) j++;
        return (i==n && j==m);
    }
// for sorting size-wise and later Lexicographically
bool cmp(string a,string b){
    if (a.size()!=b.size())
        return a.size()<b.size();
    return a.size()>b.size();
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
                if(check(words[j],words[i]))
                    dp[i]=max(dp[i],dp[j]+1);
        return *max_element(dp.begin(),dp.end());
    }
};