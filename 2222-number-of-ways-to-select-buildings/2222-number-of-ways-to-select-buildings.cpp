class Solution {
public:
    long long numberOfWays(string s) {
        long long n = s.size();
        long long leftZero = 0,totalZero = 0;
        long long leftOne  = 0,totalOne = 0;
        
        long long ans = 0;
        for(char ch : s)
        {
            totalZero += (ch == '0');
            totalOne += (ch == '1');
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans+= leftZero * (totalZero-leftZero);
            if (s[i]=='0') ans+= leftOne * (totalOne-leftOne);
            leftZero += (s[i] == '0');
            leftOne += (s[i] == '1');
        }
       return ans;
    }
};