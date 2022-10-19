class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>m;
        // multimap<int,string,greater<int>>m2;

        int n = messages.size();
        for(int i=0;i<n;i++) {
            int noOfWords = 0;
            string temp = "";
            for(auto it: messages[i]){ 
                if(it==' ') {
                    temp="";noOfWords++;
                }
                else temp+=it;
            }
        noOfWords++;
        m[senders[i]]+=noOfWords;
        }
        
        
        int cnt = 0;
        string ans = "";
        for(auto it: m) {
            int sz = it.second;
            if(sz>=cnt){
                cnt = sz;
                ans = it.first;
            }
        }
        return ans;
    }
};