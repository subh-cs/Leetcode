class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,left=INT_MAX,right=INT_MIN;
        //first index
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                left=min(left,mid);
                r=mid-1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        //re-initialize l & r
        l=0;r=nums.size()-1;
        //last index
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                right=max(right,mid);
                l=mid+1;
            }
            else if(nums[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        vector<int>v;
        if(left!=INT_MAX) v.push_back(left);
        else v.push_back(-1);
        if(right!=INT_MIN) v.push_back(right);
        else v.push_back(-1);
        return v;
    }
};