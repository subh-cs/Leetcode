bool dfsC(int node, vector<int>adj[],vector<int>&vis){
    if(vis[node]==1) return false;
    if(vis[node]==2) return true;
    vis[node]=1;
    for(auto it: adj[node])
        if(!dfsC(it,adj,vis)) return false;
    vis[node]=2;
    return true;
}
void dfsT(int node, vector<int>adj[],vector<int>&vis, vector<int>&ans){
    vis[node]=1;
    for(auto it: adj[node])
        if(!vis[it]) dfsT(it,adj,vis,ans);
    ans.push_back(node);
}
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>adj[n],vis(n,0),ans;
        //convert it into adj list
        for(auto it: pre)
            adj[it[0]].push_back(it[1]);
        //check for cycle (if cycle present, return []);
        for(int i=0;i<n;++i)
            if(!vis[i])
                if(!dfsC(i,adj,vis)) return ans;
        //reinitialize vis to 0
       fill(begin(vis),end(vis),0);
        //then toposort the graph
        for(int i=0;i<n;++i)
            if(!vis[i])
                dfsT(i,adj,vis,ans);
        //return ordering in reverse order
        return ans;
    }
};