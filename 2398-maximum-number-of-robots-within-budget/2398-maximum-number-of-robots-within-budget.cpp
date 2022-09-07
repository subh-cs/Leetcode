class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        
        
        //for maintaining maximum, monotonic queue
        deque<int>dq;long long totalRunCost=0,ans=0,i=0,j=0,n=chargeTimes.size();
        while(j<n){
            //push dq to maintain monotonic fashion
            while(!dq.empty() && dq.back()<chargeTimes[j])
                dq.pop_back();
            dq.push_back(chargeTimes[j]);
            //
            totalRunCost+=runningCosts[j];
            //
            long long cost = dq.front()+((j-i+1)*(totalRunCost));
            //until cost is below or equal to budget
            while(cost>budget){
                totalRunCost-= runningCosts[i];
                if(dq.front()==chargeTimes[i]) dq.pop_front();
                i++;
                //dq edgecase
                cost = dq.front()+((j-i+1)*(totalRunCost));
            }
            ans=max(ans,j-i+1);
            j++; 
        }
        return ans;
    }
};