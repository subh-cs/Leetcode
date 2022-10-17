class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(auto it: arr) m[it]++;
        unordered_set<int>st;
        for(auto it: m) st.insert(it.second);
        return st.size()==m.size()?1:0;
    }
};