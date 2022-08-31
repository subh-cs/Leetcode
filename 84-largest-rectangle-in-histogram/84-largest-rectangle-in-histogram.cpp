vector<int> NSL(vector<int>heights){
    vector<int>ans(heights.size());
    stack<int>st;
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        if(!st.empty()) ans[i] = st.top()+1;
        else if(st.empty()) ans[i] = 0;
        st.push(i);
    }
    return ans;
}
vector<int> NSR(vector<int>heights){
    vector<int>ans(heights.size());
    stack<int>st;
    for(int i=heights.size()-1;i>=0;i--){
        while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
        if(!st.empty()) ans[i] = st.top()+1;
        else if(st.empty()) ans[i] = heights.size()+1;
        st.push(i);
    }
    return ans;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>nsl,nsr;int ans=0;
        nsl=NSL(heights);
        nsr=NSR(heights);
        //count ans
        for(int i=0;i<heights.size();i++)
            ans=max(ans,heights[i]*(nsr[i]-nsl[i]-1));
        return ans;
    }
};