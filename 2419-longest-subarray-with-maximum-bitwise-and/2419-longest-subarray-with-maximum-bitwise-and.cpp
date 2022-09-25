class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int largest = *max_element(nums.begin(),nums.end()),n = nums.size(),maxCnt = 0,cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==largest) cnt++;
            else cnt = 0;
            maxCnt = max(cnt,maxCnt);
        }
        return maxCnt;
    }
};