class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>leftPart(n,0),rightPart(n,0);
        
        //left Part check
        int i = 0, j = 1;
        while(j<n){
            if(j-i+1<=k && nums[j]>nums[j-1])
                 i = j;
            else if(j-i+1 == k+1){
                    leftPart[j]=1;
                    i++;
                if(nums[j]>nums[j-1]) i = j;
            }
            j++;
        }
        //right Part check
         i = n-1; j = n-2;
        while(j>=0){
            if(i-j+1<=k && nums[j]>nums[j+1]) i = j;
            else if(i-j+1 == k+1){
                    rightPart[j]=1;
                    i--;
                if(nums[j]>nums[j+1]) i = j;
            }
            j--;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
            if(leftPart[i]==1 && rightPart[i]==1) ans.push_back(i);
        return ans;
    }
};