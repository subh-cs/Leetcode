class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(),cnt=1;
        vector<int>temp;temp.push_back(nums[0]);
        for (int i=1;i<n;i++) {    
        if(nums[i]>temp.back()) {temp.push_back(nums[i]);cnt++;}
        else{
            int ind = lower_bound(temp.begin()+0, temp.end(), nums[i])-temp.begin();
            temp[ind] = nums[i];
        }
    }
    return cnt>=3 ? 1:0;
    }
};