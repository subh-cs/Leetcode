class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        vector<long long>v1,v2; long long mod = 1000000007; 
        long long max_h=INT_MIN,max_w=INT_MIN;
        //top-bottom 
        v1.push_back(0);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        for(auto it:horizontalCuts)
            v1.push_back(it);
        v1.push_back(h);
        //make it diff v1
        for(int i=0;i<v1.size()-1;i++)
            max_h = max(max_h,(v1[i+1]-v1[i]));
        
        //left-right
         v2.push_back(0);
        sort(verticalCuts.begin(),verticalCuts.end());
        for(auto it:verticalCuts)
            v2.push_back(it);
        v2.push_back(w);
        //make it diff v2
        for(int i=0;i<v2.size()-1;i++)
            max_w = max(max_w,v2[i+1]-v2[i]);
        //now calculate area
        
        return (max_h*max_w) % mod;
    }
};