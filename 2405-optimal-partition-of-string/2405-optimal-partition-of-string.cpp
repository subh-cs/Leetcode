class Solution {
public:
    int partitionString(string s) {
        int n =s.size(),cnt=0;
        map<int,int>m;
        int j = 0;
        while(j<n){
            if(m.count(s[j])){
            cnt++;m.clear();
            }
            m[s[j]]++;
            j++;
        }
        return cnt+1;
    }
};