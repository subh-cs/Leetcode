bool cmp (vector<int> v1, vector<int> v2){
    if(v1[0]==v2[0]) return v1[1]<v2[1];
    return v1[0]>v2[0];
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),cmp);vector<vector<int>>ans;
        for(auto it:v)
            ans.insert(ans.begin()+it[1],it);
        return ans;
    }
};