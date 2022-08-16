class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //it'll help to store indexes with one sorted anagram of string
        map<string,vector<int>>m; 
        
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(begin(temp),end(temp));
            m[temp].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto it:m){
            vector<string>temp;
            for(auto jt:it.second)
                temp.push_back(strs[jt]);
            ans.push_back(temp);
        }
        return ans;
    }
};