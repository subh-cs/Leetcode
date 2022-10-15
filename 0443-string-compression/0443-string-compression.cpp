class Solution {
public:
    int compress(vector<char>& s) {
        int n = s.size(),cnt = 1;
        vector<pair<char,int>>v;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else {v.push_back({s[i-1],cnt});cnt=1;}
        }
        v.push_back({s[n-1],cnt});
        //
        string temp="";
        for(auto it: v){
            string num = to_string(it.second);
            temp+=it.first;
            if(num!="1") temp+=num;
        }
       s.clear();
        for(auto it: temp)
            s.push_back(it);
        return s.size();
    }
};