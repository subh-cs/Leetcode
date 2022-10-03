class Solution {
public:
    int minCost(string color, vector<int>& time) {
        int i=0,j=0;int n = color.size(),cnt=0;
        while(j<n && i<=j){
            if(i==j) j++;
            else if(color[i]=='0') i++;
            else if(color[j]=='0') j++;
            else if(i!=j && color[i]==color[j]){
                if(time[i]<=time[j]){cnt+=time[i];color[i]='0';i++;}
                else if(time[i]>time[j]){cnt+=time[j];color[j]='0';j++;}
            }
            else if(i!=j && color[i]!=color[j]){i++;j++;}
        }
        return cnt;
    }
};