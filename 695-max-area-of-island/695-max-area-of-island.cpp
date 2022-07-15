class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
int dfs(int i, int j,int m,int n, vector<vector<int>>&grid){
    if(i<0 || i>=m||j<0||j>=n || grid[i][j]==0) return 0;
    grid[i][j]=0;
    int total=0;
    for(auto it: dir)
        total+=dfs(i+it[0],j+it[1],m,n,grid);
    return total+1;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0,m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1)
                    maxi=max(maxi,dfs(i,j,m,n,grid));
        return maxi;
    }
};