/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        
        int n = m.length();
        int l = 0, r = n-1, peakInd = 0;
        
        while(l<r){
        int mid = (l+r)/2;
            if(m.get(mid)<m.get(mid+1)) l = peakInd = mid+1;
            else r = mid;
        }
        //left half
        l = 0,r = peakInd;
        while(l<=r){
        int mid = (l+r)/2;
            if(m.get(mid)==target) return mid;
            else if(m.get(mid)<target) l = mid+1;
            else r = mid-1;
        }
        //right half
        l = peakInd,r = n-1;
        while(l<=r){
        int mid = (l+r)/2;
            if(m.get(mid)==target) return mid;
            else if(m.get(mid)<target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};