class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        int n = v.size();vector<vector<int>> ans;
        sort(begin(v),end(v));
        for(int i=0;i<n-2;i++){
            int reqSum = 0-v[i];
            if(i==0|| i>0 && v[i]!=v[i-1]){
                int low = i+1, high = n-1;
            while(low<high){
                int pointerSum = v[low]+v[high];
                if(pointerSum==reqSum) {
                    vector<int>temp;
                    temp.push_back(v[i]);
                    temp.push_back(v[low]);
                    temp.push_back(v[high]);
                    ans.push_back(temp);
                while(low<high && v[low]==v[low+1]) low++;
                while(low<high && v[high]==v[high-1]) high--;
                    low++;high--;
                }
                else if(pointerSum>reqSum) high--;
                else low++;
                }
            }
        }
        return ans;
    }
};