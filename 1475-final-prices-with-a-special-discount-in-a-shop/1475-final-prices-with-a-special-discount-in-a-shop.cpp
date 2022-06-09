class Solution {
public:
    vector<int> finalPrices(vector<int>& v) {
        //next smaller right
        int n=v.size();vector<int>ans(n);stack<int>st;
        for(int i=n-1;i>=0;--i){
            if(st.empty()) ans[i]=v[i];
            else if(v[st.top()]<=v[i]) ans[i]=v[i]-v[st.top()];
            else
                while(!st.empty()&& v[st.top()]>v[i])
                    st.pop();
            if(st.empty()) ans[i]=v[i];
            else ans[i]=v[i]-v[st.top()];
        st.push(i);
        }
        return ans;
    }
};