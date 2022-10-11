class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(),cnt=1;
        vector<int>temp;temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(temp.back()<nums[i]) {temp.push_back(nums[i]);cnt++;}
            else{
                int ind = lower_bound(begin(temp),end(temp),nums[i])-begin(temp);
                temp[ind]=nums[i];
            }
        }
        return cnt;
    }
};