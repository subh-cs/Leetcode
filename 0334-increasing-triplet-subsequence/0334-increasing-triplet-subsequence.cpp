class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int>::iterator m = nums.begin(); 
    for (int& val : nums) {
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        if (it == m)
            m++;
    }
    
    return m - nums.begin()>=3 ? 1:0;
    }
};