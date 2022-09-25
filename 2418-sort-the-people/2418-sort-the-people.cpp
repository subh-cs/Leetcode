class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string,greater<int>>m;vector<string>ans;
        int n  = names.size();
        for(int i=0;i<n;i++)
            m.insert({heights[i],names[i]});
        for(auto it:m)
            ans.push_back(it.second);
        return ans;
    }
};