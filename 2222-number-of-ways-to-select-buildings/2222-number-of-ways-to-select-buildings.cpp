class Solution {
public:
    long long numberOfWays(string s) {
        long long left0 = 0, left1 = 0, count0 = 0, count1 = 0, ans = 0;
        for(char ch : s) {
            count0 += (ch == '0');
            count1 += (ch == '1');
        }
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '1')    ans += left0 * (count0 - left0);
            if(s[i] == '0')    ans += left1 * (count1 - left1);
            left0 += (s[i] == '0');
            left1 += (s[i] == '1');
        }
        return ans;
    }
};