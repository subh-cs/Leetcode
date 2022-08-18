class Solution {
public:
    bool isPalindrome(string s) {
        //make a string, and only take uppercase and lowercasse characters
        string temp;
        for(auto it:s){
            //if uppercase, convert it to lowercase and push into temp
            if(it>=65 && it<=90)
                temp.push_back(it+32);
            else if(it>=97 && it<=122)
                temp.push_back(it);
            else if(it>=48 && it<=57)
                temp.push_back(it);
        }
        //now check for palindrome
        int i=0,j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j]) return false;
            else i++;j--;
        }
        return true;
    }
};