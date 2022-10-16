class Solution {
public:
    int rev(int n){
        int num = 0;
        while(n){
            num=(num*10)+n%10;
            n/=10;
        }
        return num;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0;i <= num;i++)
            if(i+rev(i)==num) return true;
        return false;
    }
};