class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;string ans="";
        multimap<int,char,greater<int>>m;
        
        for(auto it:s)
            mp[it]++;
        for(auto it:mp)
            m.insert({it.second,it.first});
        for(auto it: m){
            int cnt = it.first;
            while(cnt--){
                ans.push_back(it.second);
                }
            }
            
        return ans;      
    }
};