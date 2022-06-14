int dp[501][501];
int f(int i,int j, string a, string b){
    if(i==a.length()||j==b.length()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) return dp[i][j]=1+f(i+1,j+1,a,b);
    return dp[i][j]= max(f(i+1,j,a,b),f(i,j+1,a,b));
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return word1.length()+word2.length()-(2*f(0,0,word1,word2));
    }
};