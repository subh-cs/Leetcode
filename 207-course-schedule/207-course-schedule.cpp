bool detectCycle(int node,vector<int>&vis,vector<int>adj[]){
    if(vis[node]==1) return false;
    if(vis[node]==2) return true;
    vis[node]=1;
    for(auto it: adj[node])
        if(!detectCycle(it,vis,adj)) return false;
    vis[node]=2; return true;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.size()==0) return true;
        vector<int>adj[n];vector<int>vis(n);
        for(auto it: p)
            adj[it[0]].push_back(it[1]);
        for(auto it: p)
            if(!detectCycle(it[0],vis,adj)) return false;
        return true;
    }
};