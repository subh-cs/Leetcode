class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod=1,zero=0;
        for(auto it: nums){
            if(it==0) zero++;
            else prod*=it;
        }
        //no zero
        if(zero==0)
            for(auto &it:nums)
                it = prod/it;
        //one zero
        else if(zero==1){
            for(auto &it:nums){
                if(it==0)
                    it=prod;
                else it=0;
            }}
        //more than one zero
        else 
            for(auto &it: nums)
                it=0;
        return nums;
    }
};