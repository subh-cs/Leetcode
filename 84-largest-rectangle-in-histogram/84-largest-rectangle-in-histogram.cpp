void NSL(vector<int> &nsl, vector<int> &heights, int n)
{

    stack<pair<int, int>> st;
    for (int i = 0; i < n; ++i)
    {
        int ans = 1;
        while (!st.empty() && st.top().first >= heights[i])
        {
            ans += st.top().second;
            st.pop();
        }
        st.push({heights[i], ans});
        nsl[i]=ans;
    }
}

void NSR(vector<int> &nsr, vector<int> &heights, int n)
{
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = 1;
        while (!st.empty() && st.top().first >= heights[i])
        {
            ans += st.top().second;
            st.pop();
        }
        st.push({heights[i], ans});
        nsr[i]=ans;
    }
}

class Solution {
public:
    int largestRectangleArea(vector<int> heights){
    int n = heights.size(), maxi = 0;
    vector<int> nsl(n), nsr(n);
    NSL(nsl, heights, n);
    NSR(nsr, heights, n);
    for (int i = 0; i < n; ++i)
        maxi = max(((nsl[i] + nsr[i] - 1) * heights[i]), maxi);
    return maxi;
}
};
