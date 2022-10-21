class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>m; int n = nums.size();
        for(int i=0;i<n;i++) {
            if(!m.count(nums[i])) m[nums[i]] = i;
            else {
                if(i - m[nums[i]]<= k) return true;
                 m[nums[i]] = i;
                 }
        }
        return false;
    }
};