bool detectCycle(vector<int>indegree,vector<int>adj[]){
    // push the values with indegree = 0;
    queue<int>q;
    for(int i=0;i<indegree.size();i++)
        if(indegree[i]==0) q.push(i);
    int count=0;
    //start bfs
    while(!q.empty()){
        int top= q.front();q.pop();
        for(auto it: adj[top]){
            indegree[it]--;
            if(!indegree[it]) q.push(it);
        }
        count++;
    }
    if(count!=indegree.size()) return false;
    return true;
}

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        if(p.size()==0) return true;
        vector<int>adj[n];vector<int>indegree(n);
        for(auto it: p){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
    return detectCycle(indegree,adj);
    }
};