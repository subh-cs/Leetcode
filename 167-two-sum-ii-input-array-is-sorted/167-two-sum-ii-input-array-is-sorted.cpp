class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        int i=0,j=v.size()-1,sum=0;vector<int> ans(2);
        while(i<j){
            sum=v[i]+v[j];
            if(sum==target){
                ans[0]=i+1;ans[1]=j+1;return ans;
            }   
            else if(sum>target)
                j--;
            else
                i++;
        }
        return ans;
    }
};