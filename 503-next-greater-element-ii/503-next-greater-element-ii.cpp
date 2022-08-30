class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        deque<int>dq;int n=nums.size();vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!dq.empty()&&dq.front()<=nums[i%n])
                dq.pop_front();
            if(!dq.empty()) ans[i%n] = dq.front();
            dq.push_front(nums[i%n]);
        }
        return ans;
    }
};