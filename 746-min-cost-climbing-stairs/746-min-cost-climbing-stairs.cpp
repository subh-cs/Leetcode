int dp[1001];
int f(int i, vector<int>&cost){
    if(i>=cost.size()) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i] = cost[i] + min(f(i+1, cost),f(i+2,cost));
}
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1, sizeof dp);
        int zero = f(0,cost);
        memset(dp,-1, sizeof dp);
        int one = f(1,cost);
        return min(zero,one);
    }
};