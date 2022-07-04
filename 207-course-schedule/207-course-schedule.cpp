//step 3 (design dfs function)
bool dfs(int node, vector<int> adj[], vector<int>&vis){
    if(vis[node]==1) return false;
    if(vis[node]==2) return true;
    vis[node]=1;
    for(auto it: adj[node])
        if(!dfs(it,adj,vis)) return false;
    vis[node]=2;
    return true;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        //step 1 (convert into adj list)
        vector<int> adj[n], vis(n,0);
        for(auto it:pre)
            adj[it[0]].push_back(it[1]);
        //step 2, call dfs for each node
        for(int i=0;i<n;++i)
            if(vis[i]!=2)
                if(!dfs(i,adj,vis)) return false;
        return true;
    }
};