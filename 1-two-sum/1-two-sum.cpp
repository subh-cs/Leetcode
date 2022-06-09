class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        map<int,int>m;
        for(int i=0;i<v.size();++i)
            if(m.count(target-v[i])==0)
                m.insert({v[i],i});
            else
                return {m[target-v[i]],i};
        return {};
    }
};