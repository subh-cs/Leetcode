class Solution {
public:
    long long int rev(int n){
        long long int num = 0;
        while(n){
            num=(num*10+n%10);
            n/=10;
        }
        return num;
    }
    bool isPalindrome(int x) {
        return x==rev(x) && x>=0 ?1:0;
    }
};