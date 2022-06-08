bool isPalindrome(string &s){
    for(int i=0;i<s.length()/2;++i)
        if(s[i]!=s[s.length()-1-i]) return false;
    return true;
}

class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0) return 0;
        if(isPalindrome(s)) return 1;
        return 2;
    }
};