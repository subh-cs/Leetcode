class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>s;int n = nums.size();
        for(auto it: nums) s.insert(it);
        for(int i=1;i<=n+1;i++)
            if(!s.count(i)) return i;
        return 1;
    }
};