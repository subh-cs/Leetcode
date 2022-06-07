class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1=0,p2=0,p=0;
        vector<int> ans(n+m);
        //pushing into the new vector with two pointers
        while(p1<m&&p2<n){
            if(nums1[p1]<nums2[p2]){
                ans[p]=nums1[p1];
                p1++;
            }
            else{
                ans[p]=nums2[p2];
                p2++;
            }
            p++;
        }
        //checking for each individual
        while(p1<m){
            ans[p]=nums1[p1];p1++;p++;
        }
        while(p2<n){
            ans[p]=nums2[p2];p2++;p++;
        }
        nums1=ans;
    }
};