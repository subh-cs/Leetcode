vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int i, int j, int m,int n, vector<vector<char>>&grid){
    if(i>=m||i<0||j>=n||j<0) return;
    if(grid[i][j]=='O'){
        grid[i][j]='#';
        for(auto it: dir)
            dfs(i+it[0],j+it[1],m,n,grid);
    }
}
class Solution {
public:
    void solve(vector<vector<char>>& grid){
        vector<vector<int>>v;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||j==0||i==m-1||j==n-1) && grid[i][j]=='O') v.push_back({i,j});
            }
        }
        for(auto it: v)
                dfs(it[0],it[1],m,n,grid);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                else if(grid[i][j]=='#') grid[i][j]='O';
            }
        }
        
    }
};