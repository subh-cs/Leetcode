int dp[101][101][201];
bool f(int i,string s1, int j, string s2, int k, string s3){
    if(k==s3.size() && i==s1.size() && j==s2.size()) return true;
    if(i<s1.size()&& s1[i]!=s3[k] && j<s2.size() && s2[j]!=s3[k] && k<s3.size()) return false;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    bool left=false,right=false;
    if(i<s1.size() && s1[i]==s3[k]) left=f(i+1,s1,j,s2,k+1,s3);
    if(j<s2.size() && s2[j]==s3[k]) right=f(i,s1,j+1,s2,k+1,s3);
    return dp[i][j][k]=(left||right);
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // vector<vector<vector<int>>>dp(101, vector<vector<int>>(101, vector<int>(201,-1)));
        memset (dp,-1, sizeof dp);
        return f(0,s1,0,s2,0,s3);
    }
};