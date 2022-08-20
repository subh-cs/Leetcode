class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int maxi = 0;
        while(i<j){
            int dist = j-i;
            maxi = max(maxi,dist*min(heights[i],heights[j]));
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxi;
    }
};