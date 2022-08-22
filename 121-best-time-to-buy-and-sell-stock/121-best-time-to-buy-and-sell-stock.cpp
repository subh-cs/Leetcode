class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),lsf=INT_MAX,op=0;
        for(int i=0;i<n;i++){
            lsf=min(lsf,prices[i]);
            op=max(op,prices[i]-lsf);
        }
        return op;
    }
};