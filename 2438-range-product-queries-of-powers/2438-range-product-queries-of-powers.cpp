class Solution {
public:
    vector<long long int> seg; 
    int n;
    int INF = 1000000007;
    //build seg tree
    void buildTree(vector<int>& nums, int pos, int left, int right){
        if (left == right){
            seg[pos] = nums[left]%INF; 
            return;
        }
        int mid = (left+right)/2;
        buildTree(nums, 2*pos+1, left, mid);
        buildTree(nums, 2*pos+2, mid+1, right);
        seg[pos]=( (seg[2*pos+1]%INF) * (seg[2*pos+2]%INF) ) % INF;
    }
    //query seg tree
    long long int rangeUtil(int qlow, int qhigh, int low, int high, int pos){
        if (qlow <= low && qhigh>= high){ // total overlap
            return seg[pos]%INF;
        }
        if (qlow > high || qhigh < low) { // no overlap
            return 1;
        }
        // partial overlap
        int mid = low+(high-low)/2;
        return (rangeUtil(qlow, qhigh, low, mid, 2*pos+1)%INF * rangeUtil(qlow, qhigh, mid+1, high, 2*pos+2)%INF) %INF;
    }
    // initialize the seg tree
    void setTree(vector<int>& nums){
        if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*n,1);  // Maximum size of a segment tree for an array of size n is 4n
            buildTree(nums, 0, 0, n-1); // Build the segment tree
        }
    }
    
    //for getting the array
    vector<int> decToBinary(int n)
{
    // array to store binary number
    vector<int>binaryNum(32);
 
    // counter for binary array
    int i = 0;
    while (n > 0) {
 
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
        vector<int>ans;
        // reverse(begin(binaryNum),end(binaryNum));
        for (int j = 0; j < i; j++) if(binaryNum[j]) ans.push_back(j);
        return ans;
}

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>v = decToBinary(n),ans;
        for(auto &it: v) it = pow(2,it);
        // revertVec(v);
        setTree(v);
        int sz = v.size();
        for(auto it: queries){
            long long answer = rangeUtil(it[0], it[1], 0, sz-1, 0); 
            // answer = pow(2,answer);
            ans.push_back(answer%INF);
        }
        return ans;    
    }
};