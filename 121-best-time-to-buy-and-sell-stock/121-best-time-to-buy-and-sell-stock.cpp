class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),mini=INT_MAX,maxi=INT_MIN,diff=0;
        vector<int>smaller(n),larger(n);
        for(int i=0;i<n;i++)
            smaller[i]=mini=min(mini,prices[i]);
        for(int i=n-1;i>=0;i--)
            larger[i]=maxi=max(maxi,prices[i]);
        for(int i=0;i<n;i++)
            diff=max(diff,abs(larger[i]-smaller[i]));
        return diff;
    }
};