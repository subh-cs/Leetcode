class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int prevTime = 0, ans = 0, prevDiff = 0;
    for (auto it : logs)
    {
        int diff = it[1] - prevTime;
        if (diff >= prevDiff)
        {
            if (diff == prevDiff)
            {
                ans = min(it[0],ans);
            }
            else
            {
                ans = it[0];
                prevDiff = diff;
            }
        }
        prevTime = it[1];
    }
    return ans;
    }
};