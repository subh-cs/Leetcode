class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>temp = nums;
        vector<int> arr = nums;
        while(temp.size()!=1){
            int n = temp.size();arr = temp;
            temp.clear();
            for(int i = 1 ;i<n;i++)
                temp.push_back((arr[i-1]+arr[i])%10);
        }
        return temp[0];
    }
};