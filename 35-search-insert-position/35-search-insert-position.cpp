class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, ans = n;
        
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]>=target){
                ans=min(ans,mid);
                r=mid-1;
            }   
            else if(nums[mid]<target)
                l=mid+1;
        }
        return ans;
    }
};