class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //make adj list
        vector<pair<int,int>>adj[n+1];
        for(auto it: times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        // make dist array, and initializing it with infinity
        vector<int>dis(n+1,INT_MAX);
        dis[0]=0; // to avoid 0 bases indexing
        //
        
        //start dijkstra
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dis[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()){
            int u = pq.top().second;pq.pop();
            for(auto it: adj[u]){
                int v = it.first;
                int wt = it.second;
                if(dis[v]>dis[u]+wt){
                    dis[v]=dis[u]+wt;
                    pq.push({dis[v],v});
                }
            }
        }

        int max_time = *max_element(begin(dis),end(dis));
        return max_time == INT_MAX ? -1 : max_time;
        
    }
};