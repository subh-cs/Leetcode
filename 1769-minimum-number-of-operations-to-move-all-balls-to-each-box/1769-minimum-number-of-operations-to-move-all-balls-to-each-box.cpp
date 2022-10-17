class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i+1;j<n;j++) if(boxes[j]=='1') sum+=(j-i);
            ans[i]+= sum;
            sum = 0;
            for(int j=i-1;j>=0;j--) if(boxes[j]=='1') sum+=(i-j);
            ans[i]+= sum;
        }
        return ans;
    }
};