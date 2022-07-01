    bool cmp(vector<int>v1,vector<int>v2){
    if(v1[1]==v2[1]) return v1[0]>v2[0];
    return v1[1]>v2[1];
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int truckSize) {
        // sort by second
        sort(b.begin(),b.end(),cmp);
        int count = 0,total=0;
        for(auto it: b){
            if(count<truckSize){
                int remain = truckSize-count;
                if(remain>=it[0]){
                count+=it[0];
                total+=(it[0]*it[1]);
                }
                else{
                count+=remain;
                total+=(remain*it[1]);
                }
            }
        }
        return total;
    }
};