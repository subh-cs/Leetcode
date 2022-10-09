class Solution {
    
public:
    // int dp[50005][50005];
    int mod = 1000000007;
    int dfs(int i, int j,int m, int n, int sum, vector<int>&ans,vector<vector<int>>& grid, int k,vector<vector<vector<int>>>&dp){
        if(i>=m||j>=n) return 0;
        if(i==m-1 && j==n-1) {
            sum+=grid[i][j];
            return sum%k == 0 ? 1:0;
        }
        if(dp[i][j][sum%k]!=-1) return dp[i][j][sum%k];
        int right = dfs(i+1,j,m,n,sum+grid[i][j],ans,grid,k,dp)%mod;
        int down = dfs(i,j+1,m,n,sum+grid[i][j],ans,grid,k,dp)%mod;
        return dp[i][j][sum%k] = (right + down)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<int>ans;
        int m = grid.size(),n=grid[0].size(),cnt =0;
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
        return dfs(0,0,m,n,0,ans,grid,k,dp);
        // for(auto it: ans) if(it%k==0) cnt++;
        // return cnt;
    }
};