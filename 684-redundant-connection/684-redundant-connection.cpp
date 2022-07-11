

// void setParent(int n){
//     for(int i=1;i<=n;i++)
//         parent[i] = i; 
// }

int findParent(int node, vector<int> &parent){
    if(node==parent[node]) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionn(int a, int b, vector<int>& parent, vector<int>& rank){
    a = findParent(a, parent);
    b = findParent(b, parent);
    if(rank[a]>rank[b])
        parent[b]=a;
    else if(rank[b]>rank[a])
        parent[a]=b;
    else{
        parent[a]=b;
        rank[a]++;
    }
}

bool isSame(int a, int b, vector<int>& parent){
    if(findParent(a, parent)==findParent(b, parent)) return true;
    return false;
}


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> rank(n+1,0);
        vector<int> parent(n+1);
        for(int i = 1;i<=n;i++)
            parent[i]=i;
        // setParent(n);
        vector<int> vis(n+1,0),ans;
        int first,last;
        for(auto it: edges){
            if(isSame(it[0],it[1],parent)){
                first = it[0];
                last = it[1];
            }
            else 
                unionn(it[0],it[1], parent, rank);
        }
        return ans={first,last};
    }
};