class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int>even;
        for(auto it: nums)
            if(it%2==0) even[it]++;
        //first check
        if(even.size()==0) return -1;
        int maxi = 0,maxnum;
        for(auto it: even)
            if(it.second>maxi) {maxi = it.second;maxnum=it.first;}
        return maxnum;
        
    }
};