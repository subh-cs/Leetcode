int findGCD(vector<int>& numsDivide) {
    int gc = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); ++i){
            gc = __gcd(gc, numsDivide[i]);
        }
    return gc;
}
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int lcd=findGCD(numsDivide),n=nums.size(),count=0;
        //if there is no common lcd, return -1;
        sort(nums.begin(),nums.end());
        for(auto it: nums){
            if(lcd%it) count++;
            else return count;
        }
        return -1;
    }
};