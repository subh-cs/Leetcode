
class Solution {
public:
    bool isPalindrome(string s){
    int n = s.size();
    int i=0,j=n-1; 
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;j--;
    }
    return true;
}
    char validChar(int ind, string s){
        for(int i=0;i<26;i++){
            char temp = s[ind];
            s[ind] = 'a'+ i;
            if(!isPalindrome(s)) return s[ind];
            s[ind] = temp;
        }
        return '0';
    }
    string breakPalindrome(string s) {
        vector<string>v;
        for(int i=0;i<s.size();i++){
            char c = validChar(i,s);
            char temp = s[i];
            if(c!='0') {s[i]=c;v.push_back(s);}
            s[i]=temp;
        }
        sort(begin(v),end(v));
        if(v.size()) return v[0];
        return "";
    }
};