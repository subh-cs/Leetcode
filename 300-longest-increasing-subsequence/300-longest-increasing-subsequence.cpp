int f(int prev, int i, int n, vector<int>& v , vector<vector<int>>&dp){
    if(i==n) return 0;
    if(dp[prev+1][i]!=-1) return dp[prev+1][i];
    int len = f(prev,i+1,n,v,dp);
    if(prev==-1||v[i]>v[prev]) len = max(1+f(i,i+1,n,v,dp), len);
    return dp[prev+1][i]=len;
}
class Solution {
public:
    int lengthOfLIS(vector<int>& text1){
        int n = text1.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(-1,0,text1.size(),text1,dp);
    }
};