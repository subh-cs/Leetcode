bool cmp(string a, string b){
    return b.size()<a.size();
}
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);string res=words[0]+"#";
        for(int i=1;i<words.size();++i)
            if(res.find(words[i]+"#")==-1) res+=words[i]+"#";
        return res.size();
    }
};