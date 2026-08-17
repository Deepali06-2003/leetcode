class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();

        int t = (n+m);
        if(n>m) return findMedianSortedArrays(nums2, nums1);

        int l = 0, h = n;
        int left_s = (t+1)/2;

        while(l<=h){
            int m1 = (l+h)>>1;
            int m2 = left_s - m1;

            int r1 = INT_MAX, r2 = INT_MAX , l1 = INT_MIN, l2 = INT_MIN;

            if(m1<n) r1 = nums1[m1];
            if(m2<m) r2 = nums2[m2];
            if(m1-1 >=0) l1 = nums1[m1-1];
            if(m2-1 >=0) l2 = nums2[m2-1];

            if(l1<=r2 && l2<=r1){
                if(t%2==0) return (double)(max(l1, l2) + min(r1, r2))/2.0;
                else return (double)max(l1, l2);
            }
            else if(l1 > r2){
                h = m1-1;
            }
            else l = m1+1;
        }
        return 0.0;
    }
};