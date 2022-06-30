class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int median = (nums.size()/2);
        int steps = 0;
        for(auto it: nums)
            steps += abs(it-nums[median]);
        return steps;
    }
};