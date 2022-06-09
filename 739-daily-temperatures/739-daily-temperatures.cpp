class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
        int n=v.size();vector<int>ans(n);stack<int>st;
        for(int i=n-1;i>=0;--i){
            if(st.empty()) ans[i]=0;
            else if(v[st.top()]>v[i]) ans[i]=st.top()-i;
            else
                while(!st.empty()&& v[st.top()]<=v[i])
                    st.pop();
            if(st.empty()) ans[i]=0;
            else ans[i]=st.top()-i;
        st.push(i);
        }
        return ans;
    }
};