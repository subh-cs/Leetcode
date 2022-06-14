int f(int i,int j, string a, string b,map<pair<int,int>,int>&m){
    if(i==a.length()||j==b.length()) return 0;
    if(m.find({i,j})!=m.end()) return m[{i,j}];
    if(a[i]==b[j]) return m[{i,j}]=1+f(i+1,j+1,a,b,m);
    return m[{i,j}]= max(f(i+1,j,a,b,m),f(i,j+1,a,b,m));
}
class Solution {
public:
    int minDistance(string word1, string word2) {
        map<pair<int,int>,int>m;
        return word1.length()+word2.length()-(2*f(0,0,word1,word2,m));
    }
};