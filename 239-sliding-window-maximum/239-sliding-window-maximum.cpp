class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(),i=0,j=0;
        vector<int> ans; deque<int> dq;
        
        while(j<n){
            //terminate all the unnecessary values
            while(!dq.empty()&& dq.back()<nums[j]) dq.pop_back();
            //Now puush
            dq.push_back(nums[j]);
            // if window size K hits
            if(j-i+1==k){
                ans.push_back(dq.front());
                if(dq.front()==nums[i]) dq.pop_front();
                i++;
            }
            j++;
        }
        return ans;
    }
};