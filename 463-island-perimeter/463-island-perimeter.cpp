
class Solution {
vector<vector<int>> dr ={{1,0},{-1,0},{0,1},{0,-1}};
int count=0;
void dfs(int i, int j, int m ,int n, vector<vector<int>>&grid){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0) {count++; return;}
    if(grid[i][j]==2) return;
    grid[i][j]=2;
    for(auto it: dr)
        dfs(i+it[0],j+it[1],m,n,grid);
    // grid[i][j]=1;
}
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n= grid[0].size();
        // vector<vector<int>>vis(m,vector<int>(n,0));
        // count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(i, j, m, n, grid);break;
            }
        }
    }
        return count;
    }
};